public class B extends A{
    public B(){
        System.out.println("B's constructor");
    }

    public static void main(String[] args) {
        B b = new B();//here we can see the invocation of super constructors of our ancestors(super classes)
    }
}
