import java.io.PrintWriter;
import java.io.IOException;
import javax.servlet.ServletException;
import javax.servlet.annotation.WebServlet;
import javax.servlet.http.HttpServlet;
import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpServletResponse;

@WebServlet("/hello")
public class HelloServlet extends HttpServlet {

    protected void doGet(HttpServletRequest request, HttpServletResponse response) throws ServletException, IOException {

        response.setContentType("text/html");
        PrintWriter writer = response.getWriter();
        try {
            writer.println("<h2>Hello from HelloServlet</h2>");
        } finally {
            writer.close();
        }
    }
}
/*Сервлет представляет специальный тип классов Java, который выполняется на веб-сервере и который обрабатывает запросы
и возвращает результат обработки.
* Класс сервлета наследуется от класса HttpServlet. Перед определением класса указана аннотация WebServlet, которая
указывает, с какой конечной точкой будет сопоставляться данный сервлет. То есть данный сервлет будет обрабатывать
запросы по адресу "/hello".

Для обработки GET-запросов (например, при обращении к сервлету из адресной строки браузера) сервлет должен
переопределить метод doGet. То есть, к примеру, в данном случае get-запрос по адресу /hello будет обрабатываться методом doGet.

Этот метод принимает два параметра. Параметр типа HttpServletRequest инкапсулирует всю информацию о запросе. А
параметр типа HttpServletResponse позволяет управлять ответом. В частности, с помощью вызова
response.setContentType("text/html") устанавливается тип ответа (в данном случае, мы говорим, что ответ представляет
код html). А с помощью метода getWriter() объекта HttpServletResponse мы можем получить объект PrintWriter, через
который можно отправить какой-то определенный ответ пользователю. В данном случае через метод println() пользователю
отправляет простейший html-код. По завершению использования объекта HttpServletResponse его необходимо закрыть с
помощью метода close().

Для запуска сервлета воспользуемся опять же контейнером сервлетов Apache Tomcat. В каталоге Tomcat в папке webapps
создадим каталог для нового приложения, который назовем helloapp.

В папке приложения классы сервлетов должны размещаться в папке WEB-INF/classes. Создадим в каталоге helloapp папку
WEB-INF, а в ней папку classes. И в папку helloapp/WEB-INF/classes поместим файл HelloServlet.java.
* */