#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>
#include<time.h>
#include<pthread.h>
#include<sys/neutrino.h>


pthread_barrier_t barrier; // объект синхронизации типа "барьер"

void *thread1 (void *not_used)
{
	time_t now;
	time (&now);	
	printf ("thread1 starting at %s", ctime (&now));

	// выполнение вычислений

	// пауза

	sleep (20);
	pthread_barrier_wait (&barrier);
	// после этого момента все три потока завершены
	time (&now);
	printf ("barrier in thread1() done at %s", ctime (&now));

}

void *thread2 (void *not_used)
{
	time_t now;
	time (&now);
	printf ("thread2 starting at %s", ctime (&now));
	// выполнение вычислений
	// пауза
	sleep (40);
	pthread_barrier_wait (&barrier);
	// после этого момента все три потока завершены
	time (&now);
	printf ("barrier in thread2() done at %s", ctime (&now));

}

int main () // игнорировать аргументы
{
	time_t now;
	// создать барьер со значением счетчика 
	pthread_barrier_init (&barrier, NULL, 3);
	// стартовать два потока thread1 и thread2
	pthread_create (NULL, NULL, thread1, NULL);
	pthread_create (NULL, NULL, thread2, NULL);
	// потоки thread1 и thread2 выполняются
	// ожидание завершения
	time (&now);
	printf ("main() waiting for barrier at %s", ctime (&now));
	pthread_barrier_wait (&barrier);
	// после этого момента все три потока завершены
	time (&now);
	printf ("barrier in main() done at %s", ctime (&now));
	pthread_exit( NULL );
	return (EXIT_SUCCESS);

}