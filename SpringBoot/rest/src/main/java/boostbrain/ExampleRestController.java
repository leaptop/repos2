package boostbrain;

import org.springframework.web.bind.annotation.RequestMapping;
import org.springframework.web.bind.annotation.RequestMethod;
import org.springframework.web.bind.annotation.RestController;

import static org.springframework.util.MimeTypeUtils.APPLICATION_JSON_VALUE;

@RestController
public class ExampleRestController {
    public static class RestResponse {
        private String param1;
        private String param2;

        public String getParam1() {
            return param1;
        }

        public void setParam1(String param1) {
            this.param1 = param1;
        }

        public String getParam2() {
            return param2;
        }

        public void setParam2(String param2) {
            this.param2 = param2;
        }
    }

    @RequestMapping(value = "/hello", //hello is the address of our method
            method = RequestMethod.GET,//http://localhost:8080/hello?name=World will set
            produces = APPLICATION_JSON_VALUE)// param2 as "World"
    public RestResponse restMethod(String name) {//ответ(то, что видим в браузере)
        RestResponse result = new RestResponse();//это JSON, в котором параметр1 - Hello
        result.setParam1("Hello");//а второй - World
        result.setParam2(name);// В итоге получили проект, который даже проще, чем тот,
//который получили из архетипа(69 и 73). Также прикрутили к проекту RestController.
// Предоставили простейший Rest api.

        return result;
    }
}
