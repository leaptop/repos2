 class Super {
    int a = 1;
}

class Child extends Super {
    int a = 2;

    public static void main(String args[]) {
        //super();
        int a = 3;

       // System.out.println(super.a);
    }
    void f(){
        super.a = 5;
        //super();
    }
}
