import java.io.*;

public class Data implements Serializable {
    public static String f1;
    public static transient int f2;
    public transient boolean f3;
    public final static String f4 = "4"; public String f5 = "5";

    volatile int x ;
    int y;
    public void printY(){
        System.out.println("y = "+ y);
    }
    public void printx(){
        System.out.println("x = "+ x);
    }
    public void changeXandY(){
         x = 56;
         x+=2;
         y = x;
    }
    public void changeY(){
        y = x;
    }
    int i6;
    Integer i7;
        private int i5 = 1;
        public void f() { int i5;
// 1
            Integer i8;
            System.out.println("i6 = "+i6);
            System.out.println("i7 = "+i7);
          //  System.out.println("i8 = "+i8);
        }

    public static void main(String[] args) {
        Data d = new Data();
        d.f1 = "fl";
       // d.f2 = "f2";
        d.f3 = true;
        d.changeXandY();
        d.printx();
        d.printY();
d.f();
      // int y =
//        ObjectOutputStream out = new ObjectOutputStream( new FileOutputStream("/file.ser"));
//
//        out.writeObject(d); out.close();
//        ObjectInputStream in = new ObjectInputStream new FileInputStream("/file.ser"));
//        d = (Data) in.readObject();
//        in.close();
    }
}
//
