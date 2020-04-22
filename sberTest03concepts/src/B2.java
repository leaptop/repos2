import java.io.*;

public class B2 implements Serializable {
    public static void main(String[] args) {
        A2 a = new A2();
        try {
            ObjectOutputStream os = new ObjectOutputStream(new FileOutputStream("test.ser")
            );
            os.writeObject(a);
            os.close();
            System.out.print(a.b + " ");
            ObjectInputStream is = new ObjectInputStream(
                    new FileInputStream("test.ser")
            );
            A2 s2 = (A2) is.readObject();
            is.close();
            System.out.println(s2.a + " " + s2.b);
        } catch (Exception ex) {
            ex.printStackTrace();
        }
    }
}