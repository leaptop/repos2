package bbyh.servlet;

import org.springframework.http.HttpStatus;
import org.springframework.util.StringUtils;

import javax.servlet.ServletException;
import javax.servlet.annotation.WebServlet;
import javax.servlet.http.HttpServlet;
import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpServletResponse;
import javax.servlet.http.HttpSession;
import java.io.IOException;

@WebServlet("/servlet")
public class HttpSessionServlet extends HttpServlet {

    private static final String NAME = "name";

    //Это типа низкоуровневая реализация:
    @Override//Здесь с помощью сервлета отправляем запрос, получаем ответ:
    protected void doGet(HttpServletRequest req, HttpServletResponse resp) throws IOException {
        HttpSession httpSession = req.getSession();//(1)прямой доступ к данным сессии через объект HttpSession
        if(httpSession == null){//(2)чтобы получить объект сессии мы используем метод getSession() от нашего
            //запроса. Если в запросе сессия пустая, то это, очевидно, ошибка.
            resp.setStatus(HttpStatus.INTERNAL_SERVER_ERROR.value());
            return;
        }
//Алгоритм обработки запроса в этом сервлете:
        //(1) достаём объект сессии; (2) если объект сессии отсутствует, возвращаем ошибку

        String name = req.getParameter(NAME);//(3)сначала пытаемся взять параметр запроса из самого запроса
        //так задумано, что в запросе содержалось какое-то имя, которое мы будем вводить в строковом виде
        if(!StringUtils.isEmpty(name)){//(4)если имя в запросе присутствует, то кладём в сессию это имя
            //как атрибут и выводим строку о том, что получили новое имя.
            httpSession.setAttribute(NAME, name);//(5)а это чтобы положить атрибут(имя, значение)
            //положить внутрь сессии мы можем объект любого класса
            resp.getWriter().println("New name have been received - " + name);
            return;
        }
//Дополняем параметры сессии с пом. метода getAttribute(имя атрибута, который мы хотим получить)
        Object nameAttribute = httpSession.getAttribute(NAME);//(6)если в запросе не было имени,
        //то пытаемся достать этот атрибут из сессии.
        if(!(nameAttribute instanceof String)){//(7)достаём обджект. Проверяем, что он инстанс от Стринга
            resp.getWriter().println("There is no saved name");//если он не является строкой, то говорим,
            return;//что в сессии нет атрибутов
        }

        String currentName = (String) nameAttribute;//(8)преобразуем атрибут к строке
        resp.getWriter().println("Current name: " + currentName);//выводим в ответе пользователю, т.е.
    }//возвращаем в браузер. Запускаме сревер.
}
