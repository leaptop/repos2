import java.util.ArrayList;
import java.util.Arrays;
import java.util.List;
import java.util.Optional;
import java.util.function.Predicate;

public class Jenerics_2 {
    public static void main(String[] args) throws BusinessException {
        String[] p = {"1", "2", "3" };

        //List<?> Iist2 = new ArrayList<Integer>(Arrays.asList(p));
        // List<Integer> list2 = new ArrayList<>(Arrays.asList(p));
        //List<Integer> list2 = new ArrayList<Integer>(Arrays.asList(p));
        List<?> list2 = new ArrayList<>(Arrays.asList(p));


        A<?> о = new A<>();
        A<Number> о1 = new A<>();
        A<?> о2 = new A<Number>();
        A<?> о3 = new A();

        ArrayList<String> aa = new ArrayList<>(10);

//        Optional<String> op = Optional.of(null);
//        System.out.println("op.toString() = " + op.toString());

        System.out.println("before Arrays.asList(1, 2, 3).stream().peek(i -> System.out.println(i));");
        // Arrays.asList(1, 2, 3).stream().peek(i -> System.out.println(i));
        Arrays.asList(1, 2, 3).stream().forEach(i -> System.out.println(i));
        System.out.println("after Arrays.asList(1, 2, 3).stream().peek(i -> System.out.println(i));");
        Predicate<Object> p2 = Predicate.isEqual(2).and(Predicate.isEqual(null));
        System.out.println("p2.test(2)" + p2.test(2));

//        Optional<String> opt = new List<String>();// С ЭТИМ РАЗОБРАТЬСЯ
//        String value = opt.orElse("default");
//        String value2 = opt.get();
        // String value3 = opt.ifPresent();
        //String value4 = Optional.of(opt);
        try {
            throw new BusinessException(56);
        } catch (BusinessException ex) {
            ex.meth();
            System.out.println("catching part");
        }

    }

    public void ml(List<? extends Number> list) {
        Number n = list.get(0);
    }
    // List<Number extends ?>
    //List<? super Number>
    // List<? extends Number>
    // List<?>

}
