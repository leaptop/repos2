class JThread extends Thread {

    JThread(String name){
        super(name);
    }

    public void run(){

        System.out.printf("%s started... \n", Thread.currentThread().getName());
        try{
            Thread.sleep(500);
        }
        catch(InterruptedException e){
            System.out.println("Thread has been interrupted");
        }
        System.out.printf("%s finished... \n", Thread.currentThread().getName());
    }
}

public class ProgramThreadExample {

    public static void main(String[] args) {

        System.out.println("Main thread started...");//В этом то и прикол. Main сам по себе отрабатывает моментально эти
        //две строки: "Main thread started...", "Main thread finished...". А вот JThread работает параллельно мейну.
        new JThread("JThread").start();
        System.out.println("Main thread finished...");
    }
}