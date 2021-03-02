import java.io.Externalizable;
import java.io.Serializable;

public class Program {

    public static void main(String[] args) {

        Day current = Day.MONDAY;
        System.out.println(current);    // MONDAY
        current.retr();
    }
}
interface MyInterface{
    public void u();
        }
enum Day implements MyInterface {

    MONDAY(450),
    TUESDAY(20),
    WEDNESDAY,
    THURSDAY,
    FRIDAY,
    SATURDAY,
    SUNDAY;
    int weight;

   public void u(){

}
    public void retr() {
        System.out.println(ttt);
        System.out.println("Constructor's value w is: "+ weight);
    }

    int ttt = 8;

    Day() {

    }

    Day(int w) {
        weight = w;
    }
}