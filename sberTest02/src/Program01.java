class JThread01 extends Thread {

    JThread01(String name){
        super(name);
    }
    public void run(){

        System.out.printf("%s started... \n", Thread.currentThread().getName());
        int counter=1; // счетчик циклов
        while(!isInterrupted()){//a built in function for checking if our thread is interrupted

            System.out.println("Loop " + counter++);
        }
        System.out.printf("%s finished... \n", Thread.currentThread().getName());
    }
}
public class Program01 {

    public static void main(String[] args) {

        System.out.println("Main thread started...");
        JThread01 t = new JThread01("JThread01");
        t.start();
        try{
            Thread.sleep(150);
            t.interrupt();

            Thread.sleep(150);
        }
        catch(InterruptedException e){
            System.out.println("Thread has been interrupted");
        }
        System.out.println("Main thread finished...");
    }
}