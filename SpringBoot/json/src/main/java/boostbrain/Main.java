package boostbrain;//https://www.youtube.com/watch?v=ZDk4UnOHXXA

import com.fasterxml.jackson.core.JsonProcessingException;
import com.fasterxml.jackson.databind.ObjectMapper;

import java.io.IOException;

public class Main {
    public static void main(String[] args) throws IOException {
        ObjectMapper objectMapper = new ObjectMapper();//third example
        SomeData someData = new SomeData();
        InnerObject innerObject = new InnerObject();
        innerObject.setParam1("Hello");
        innerObject.setParam2("People");
        someData.setInnerObject(innerObject);

        //someData.setArray(new int[]{1,2,3,4,5,6,7,8,9,10});//second
//        someData.setParam(100);//first case scenario
//        someData.setParam2(true);
//        someData.setParam3("boostbrainsss");

        String result = objectMapper.writeValueAsString(someData);//to avoid the red waves here I added exception to method signature
        System.out.println(result);//then you put the output(like {"param":100,"param2":true,"param3":"boostbrainsss"})
        // to https://jsonformatter.curiousconcept.com/ to better see what's inside and to make sure, that the output text
        //is valid JSON

        //fourth example:
        //обратное преобразование: принимаем текст и параметр класса, который возвращает эта функция
        SomeData newData = objectMapper.readValue(result, SomeData.class);
        System.out.println(newData);//you put a breakpoint here and press debug and see
        //what's inside of the newData object. And you'll see the parameters, that we passed there from JSON.
    }
}
