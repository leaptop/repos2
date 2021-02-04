#include <stdio.h>

#include <stdlib.h>

#include <time.h>

#include <signal.h>

#include <errno.h>

#include <unistd.h>

#include <sys/siginfo.h>

#include <sys/neutrino.h>

// Получаемые сообщения

// Сообщения

#define MT_WAIT_DATA 2 // Сообщение от клиента

#define MT_SEND_DATA 3 // Сообщение от клиента

// Импульсы

#define CODE_TIMER 1 // Импульс от таймера

// Отправляемые сообщения

#define MT_OK       0 // Сообщение клиенту

#define MT_TIMEDOUT 1 // Сообщение клиенту

// Структура сообщения

typedef struct {

 int messageType; // Содержит сообщение от клиента и

                  // клиенту

 int messageData; // Опциональные данные, зависят от

                  // сообщения

} ClientMessageT;

typedef union {

 ClientMessageT msg;  // Сообщение может быть

                      // либо обычным,

 struct _pulse pulse; // либо импульсом

} MessageT;

// Таблица клиентов

#define MAX_CLIENT 16 // Максимум клиентов

                      // одновременно

struct {

 int in_use;  // Элемент используется?

 int rcvid;   // Идентификатор

              // отправителя клиента

 int timeout; // Оставшийся клиенту

              //тайм-аут

} clients[MAX_CLIENT]; // Таблица клиентов

int chid; // Идентификатор канала

          // (глобальный)

int debug = 1; // Режим отладки, 1 ==

               // вкл, 0 == выкл

char *progname = "time1.c";

// Предопределенные прототипы

static void setupPulseAndTimer(void);

static void gotAPulse(void);

static void gotAMessage(int rcvid, ClientMessageT *msg);

/*

 * setupPulseAndTimer

 *

 * Эта подпрограмма отвечает за настройку импульса, чтобы

 * тот отправлял сообщение с кодом MT_TIMER.

 * Затем устанавливается

 * периодический таймер с периодом в одну секунду.

*/

void setupPulseAndTimer(void) {

 timer_t timerid; // Идентификатор таймера

 struct sigevent event; // Генерируемое событие

 struct itimerspec timer; // Структура данных

                          // таймера

 int coid; // Будем соединяться с

           // собой

 // Создать канал к себе

 coid = ConnectAttach(0, 0, chid, 0, 0);

 if (coid == -1) {

  fprintf(stderr, "%s: ошибка ConnectAttach!\n", progname);

  perror(NULL);

  exit(EXIT_FAILURE);

 }

 // Установить, какое событие мы хотим сгенерировать

 // - импульс

 SIGEV_PULSE_INIT(&event, coid, SIGEV_PULSE_PRIO_INHERIT,

  CODE_TIMER, 0);

 // Создать таймер и привязать к событию

 if (timer_create(CLOCK_REALTIME, &event, &timerid) ==

  -1) {

  fprintf(stderr,

   "%s: не удалось создать таймер, errno %d\n",

   progname, errno);

  perror(NULL);

  exit(EXIT_FAILURE);

 }

 // Настроить таймер (задержка 1 с, перезагрузка через

 // 1 с) ...

 timer.it_value.tv_sec = 1;

 timer.it_value.tv_nsec = 0;

 timer.it_interval.tv_sec = 1;

 timer.it_interval.tv_nsec = 0;

 // ...и запустить его!

 timer_settime(timerid, 0, &timer, NULL);

}
/*

 * gotAPulse

 *

 * Эта подпрограмма отвечает за обработку тайм-аутов.

 * Она проверяет список клиентов на предмет тайм-аута

 * и отвечает соответствующим сообщением тем клиентам,

 * у которых тайм-аут произошел.

*/

void gotAPulse(void) {

 ClientMessageT msg;

 int i;

 if (debug) {

  time_t now;

  time(&now);

  printf("Получен импульс, время %s", ctime(&now));

 }

 // Подготовить ответное сообщение

 msg.messageType = MT_TIMEDOUT;

 // Просмотреть список клиентов

 for (i = 0; i < MAX_CLIENT; i++) {

  // Элемент используется?

  if (clients[i].in_use) {

   // Тайм-аут?

   if (--clients[i].timeout == 0) {

    // Ответить

    MsgReply(clients[i].rcvid, EOK, &msg, sizeof(msg));

    // Освободить элемент

    clients[i].in_use = 0;

   }

  }

 }

}

/*

 * gotAMessage

 *

 * Эта подпрограмма вызывается при каждом приеме

 * сообщения. Проверяем тип

 * сообщения (либо «жду данных», либо «вот данные»),

 * и действуем

 * соответственно. Для простоты предположим, что данные

 * никогда не ждут.

 * Более подробно об этом см. в тексте.

*/

void gotAMessage(int rcvid, ClientMessageT *msg) {

 int i;

 // Определить тип сообщения

 switch (msg->messageType) {

 // Клиент хочет ждать данных

 case MT_WAIT_DATA:

  // Посмотрим, есть ли пустое место в таблице клиентов

  for (i = 0; i < MAX_CLIENT; i++) {

   if (!clients[i].in_use) {

    // Нашли место - пометить как занятое,

    // сохранить rcvid

    // и установить тайм-аут

    clients[i].in_use = 1;

    clients[i].rcvid = rcvid;

    clients[i].timeout = 5;

    return;

   }

  }

  fprintf(stderr,

   "Таблица переполнена, сообщение от rcvid %d"

   " игнорировано, клиент заблокирован\n", rcvid);

  break;

  // Клиент с данными

 case MT_SEND_DATA:

  // Посмотрим, есть ли другой клиент, которому можно ответить

  // данными от этого клиента

  for (i = 0; i < MAX CLIENT; i++) {

   if (clients[i].in_use) {

    // Нашли - использовать полученное сообщение

    // в качестве ответного

    msg->messageType = MT_OK;

    // Ответить ОБОИМ КЛИЕНТАМ!

    MsgReply(clients[i].rcvid, EOK, msg, sizeof(*msg));

    MsgReply(rcvid, EOK, msg, sizeof(*msg));

    clients[i].in_use = 0;

    return;

   }

  }

  fprintf(stderr,

   "Таблица пуста, сообщение от rcvid %d игнорировано,"

   " клиент заблокирован\n", rcvid);

  break;

 }

}


int main (void) // Игнорировать аргументы

               // командной строки

{

 int rcvid; // PID отправителя

 MessageT msg; // Само сообщение

 if ((chid = ChannelCreate(0)) == -1) {

  fprintf(stderr, "%s: не удалось создать канал!\n",progname);

  perror(NULL);

  exit(EXIT_FAILURE);

 }

 // Настроить импульс и таймер

 setupPulseAndTimer();

 // Прием сообщений

 for(;;) {

  rcvid = MsgReceive(chid, &msg, sizeof(msg), NULL));

  // Определить, от кого сообщение

  if (rcvid == 0) {

   // Здесь неплохо бы еще проверить поле «code»...

   gotAPulse();

  } else {

   gotAMessage(rcvid, &msg.msg);

  }

 }

 // Сюда мы никогда не доберемся

 return (EXIT_SUCCESS);

}
