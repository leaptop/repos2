package bbyh.bean;

import lombok.Data;
import org.springframework.stereotype.Component;
import org.springframework.web.context.annotation.SessionScope;

@Data
@SessionScope
@Component
public class HttpSessionBean {//сохранение и изменение сессионных данных через т.н. сессионный бин, а
    //сессионный бин - тот, который помечен аннотацией SessionScope. Из браузера прямого доступа нет к бину.
    //Поэтому прослойкой служит контроллер HttpSessionController
    private String name;
}
