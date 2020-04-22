public class Program2 {
    static class MyThread extends Thread {
        public void run() {
            System.out.print("Thread");
        }
    }

    volatile int x;

    public static void main(String[] args) {
        MyThread t = new MyThread();
        t.start();
Program2 p2 = new Program2();
        p2.x+=2;
        p2.x = 5;
        int y = p2.x;

        System.out.print("one. ");
        t.start();

        System.out.print("t«o. ");

        System.out.print("Thread ");

    }
}



