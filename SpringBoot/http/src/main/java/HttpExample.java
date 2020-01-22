import org.apache.http.client.HttpClient;
import org.apache.http.*;
import org.apache.http.client.methods.HttpGet;
import org.apache.http.client.methods.HttpPost;
import org.apache.http.impl.client.HttpClients;
import org.apache.http.util.EntityUtils;

import java.io.IOException;

public class HttpExample {
    public static void main(String[] args) throws IOException {
        HttpClient httpClient = HttpClients.createDefault();//создали экземпляр http клиента через утилитарный класс HttpClients

        HttpGet httpGet = new HttpGet("http://yandex.ru");//создали экземпляр get запроса
        HttpResponse httpResponse = httpClient.execute(httpGet);//исполняем запрос с помощью http клиента httpClient.
        // Получаем ответ.

        String body = EntityUtils.toString(httpResponse.getEntity());//сюда брейкпоинт. Смотрим httpResponse original
        //code = 200 - Ok
        //чтобы вытащить данные из httpResponse используем
        //утилитарный класс EntityUtils. Получаем т.н. entity.
        System.out.println(body);//в body имеем тело ответа

        //пример пост-запроса:
        HttpPost httpPost = new HttpPost("http://yandex.ru");//создали экземпляр запроса, обратились на яндекс
        httpPost.setHeader("qwe", "qwe");//от балды. Демонстрация установки хедеров.
        httpResponse = httpClient.execute(httpPost);//дальше точно так же

        body =EntityUtils.toString(httpResponse.getEntity());//сюда брейкпоинт. Здесь запрос ошибочный, поэтому code = 403
        //и хедеров немного...
        System.out.println(body);
        //яндекс не понял, что за get запрос мы хотим туда послать, не понял что это за заголовки.
    }
}
