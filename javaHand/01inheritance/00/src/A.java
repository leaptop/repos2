public class A extends Parent implements Ainterface, Binterface {//as we can see inheritance is only possible to one class(only one class
    //can be a parent to one class. And we can also see, that multiple implementation of interfaces is available.
    public A(){
        System.out.println("A's constructor");
    }

}
