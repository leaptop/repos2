import java.lang.reflect.Array;
//import java.util.
import java.util.*;//contents Collections
import java.util.stream.Stream;

//package sberTest02.src;
public class Main {
    //stopped at 19:18
//    int xx;
//    String st;
//    public static void main(String[] args) {
//        Main m = new Main();
//        System.out.println(m.xx);
//        System.out.println("st = "+m.st);
//
//    }

    //-----------------------------------------------------
//public class Main extends Parent {
//    static int a = 2;
//
//    public static void main(String[] args) {
//         int a = 3;
//        // System.out.println(super.a);//it's a bug. super.a can't be referenced from a static context
//        System.out.println("Parent.a = " + Parent.a);//the way to make it working is to declare a static and call it Parent.a
    //----------------------------------------
//int a = 3;
//Super s = new Super();
//        System.out.println(s.a);
//    }
    //--------------------------------
  //  public static void main(String[] args) {

//        int c = 7;
//        int result = 4;
//        result += ++c;//if outside a method, then it's a bug
//        System.out.print(result);
//    }
        //----------------------------------------
//        int x = 5 * 4 % 3;//the rule "from right to left" works only during multiple variable assignment e.g.: int a = b = 2*2;
//        System.out.print(x);//but operations with numbers still go from left to right(in accordance to priority ofcourse)
//    }
        //--------------------------------------------------
//    // int[] i = new int[4];//arrays can
//    // Main m = new Main();//objects can't: foreach not applicable for type Main
//    //HashSet<Main> hs = new HashSet<>(10);//collections can
//    //any types, implementing the Iterable interface can be put in foreach loop
//        AbstractList<Integer> aa = new AbstractList<Integer>() {
//            @Override
//            public Integer get(int index) {
//                return null;
//            }
//            @Override
//            public int size() {
//                return 0;
//            }
//        };
//        //aa.add(78);
//       // aa.set(4, 98);
//        aa.get(8);
//        for (Object o : aa) {
//            System.out.println(o.toString());
//        }
        //-------------------------------------------------
//        int x = -1;
//        if (x % 2 == 1) {
//            System.out.println("odd");
//        } else {
//            System.out.print("Even");
//        }
//    }
        //---------------------------------------------------------------
//        Main a = new Main();
//        a = null;
        //and there is also a tricky question: Какой из двух фрагментов кода предотвратит возникновение NullPointerException?
        //Можно подумать, что код прямо создан для предотвращения чего-то. Но там просто один фрагмент может вызвать нулпоинтер, а второй нет.
//        if (a != null && a.size > 0) {/*fragment 1*/}//this code will work everytime. The idea is that even here syntax is wrong. But the compiler doesn't go the part with a bug(a.size), because the first condition is false.
//        if (a != null & a.size > 0) {/*fragment 2*/}//this code calls a nullpointer exception when a equals null. Because the & operator is called nevertheless a is null or not.
        //------------------------------------------------------
//Какой примитивный тип не может быть приведён к любому другому примитивному типу?
//        int char boolean long
//В принципе можно сделать функцию для перевода булеан в 1 или 0, но такой перевод не реализован по умолчанию, поэтому
//скорее всего здесь ответ: булеан. Но это не точно. Точно. Нашёл подтверждающую табличку http://pr0java.blogspot.com/2015/12/java.html
//-------------------------------------------------------------
//        Integer a;
//        System.out.println(a);//ошибка компиляции, т.к. а не инициализирована
//    }
//-----------------------------------------------------------
//        A aaa = new A();
//        aaa.f();
//        try {
//            System.out.println("inside Main \n");
//            Thread.sleep(10000000);
//        }catch (Exception e){}
        //----------------------------------
//    public static void main(String[] args) {
//
//    A cl = new A();
//    Super sr = new Super();//здесь класс может быть и не статсическим, т.к. лежит вне Main
//        cl.f();
//}
//static class A {//класс вложенный внутрь объекта Main д.б. статическим
//    private int i = 1;
//
//    public void f() {
//        int i;
//        System.out.println("i = " + i);//ошибка компиляции(i не инициализирована)
//        //1
//    }
//}
//----------------------------------------------------------------------
//        //Test.
//        Test tst = new Test();//fisrt answer is true, it's visible from inside Test and package
//        tst.a = 8;
//        System.out.println("tst.a = " +tst.a);
//
//        ExtendingTest et = new ExtendingTest();//the second answer is also true, a is available from the extending
//        et.a = 90;                            //Test classes
//        System.out.println("et.a = " + et.a);
//--------------------------------------------------------------------------
public static void main(String[] args) {
    Integer [] a0 = {1,6,9,45,12};
    Collection cl = Arrays.asList(a0);
   // Collection cl = Collections.//says that Collections.asList() doesn't exist
    List<Integer> arr = Arrays.asList(a0); //doesn't work

    cl.stream();
    Stream str = Stream.builder().addAll



    String[] a = { "foo", "bar", "baz"};
    List<String> list = Arrays.asList(a);
    System.out.println(list); // [foo, bar, baz]

    a[0] = "aaa";
    System.out.println(list); // [aaa, bar, baz]

}




    }

//}
//--------------------------------------------------------------

//class Parent {
//    static int a = 1;
//
//    //public static void main(String[] args) {
//    //int a = 3;
//
//
//}

//-----------------------------------------------------------------------------------


