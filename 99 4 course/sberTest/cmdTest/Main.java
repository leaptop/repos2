import java.util.AbstractList;
import java.util.HashSet;
import java.util.Iterator;
public class Main {
    public static void main(String[] args) {
//int a = 3;
//Super s = new Super();
//        System.out.println(s.a);
//    }
//    int c = 7;
//    int result = 4;
//    result += ++c;//if outside a method, then it's a bug
//    System.out.print(result);
//    int x = 5 * 4 % 3;//the rule "from right to left" works only during multiple variable assignment e.g.: int a = b = 2*2;
//    System.out.print(x);//but operations with numbers still go from left to right(in accordance to priority ofcourse)
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
//        int x = -1;
//        if (x % 2 == 1) {
//            System.out.println("odd");
//        } else {
//            System.out.print("Even");
//        }
//        Main a = new Main();
//        a = null;
        //and there is also a tricky question: Какой из двух фрагментов кода предотвратит врзникновение NullPointerWxception?
        //Можно подумать, что код прямо создан для предотвращения чего-то. Но там просто один фрагмент может вызвать нулпоинтер, а второй нет.
//        if (a != null && a.size > 0) {/*fragment 1*/}//this code will work everytime. The idea is that even here syntax is wrong. But the compiler doesn't go the part with a bug(a.size), because the first condition is false.
//        if (a != null & a.size > 0) {/*fragment 2*/}//this code calls a nullpointer exception when a equals null. Because the & operator is called nevertheless a is null or not.
//Какой примитивный тип не может быть приведён к любому другому примитивному типу?
//        int char boolean long
//В принципе можно сделать функцию для перевода булеан в 1 или 0, но такой перевод не реализован по умолчанию, поэтому
//скорее всего здесь ответ: булеан. Но это не точно. Точно. Нашёл подтверждающую табличку http://pr0java.blogspot.com/2015/12/java.html

        //Integer a = 78;
        System.out.println("hi there");//ошибка компиляции, т.к. а не инициализирована


    }
}