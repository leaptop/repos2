import java.time.LocalDateTime;
import java.time.ZoneId;
import java.time.temporal.ChronoUnit;
import java.util.Arrays;

public class TesterAA {
    int aa;
    Integer aaa;
    public static void main(String[] args) {
        TesterAA tst = new TesterAA();
        tst.m();

        LocalDateTime now = LocalDateTime.now();
        now.atZone(ZoneId.of("UTC"));	// 1
        now.plus(1, ChronoUnit.WEEKS);	// 2
        now.withHour(0); //3

    }
    public void m(){
        AA a = new AA();
        a.m(1, 3L, 4.4f);
        System.out.println("aa = " + aa);
        System.out.println("aaa = " + aaa);
        int i;
        Integer iii;
       // System.out.println("i = " + i);
        //System.out.println("iii = " + iii);

        Arrays.asList(1, 2, 3).stream().peek(iiii -> System.out.println(iiii));// один из вопросов из будущего
    }
}
