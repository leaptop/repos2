public class Main {
    public static void main(String[] args) {
        Empty em = new Empty();
        Empty em2 = new Empty();
        Empty em3 = new Empty();
        Empty em4 = em3;
        System.out.println("em.hashCode() = "+em.hashCode());
        System.out.println("em2.hashCode() = "+em2.hashCode());//two similar objects give different hash numbers... Though habr says it has to return the same hashes...
        System.out.println("em2.hashCode() = "+em2.hashCode());
        System.out.println("em3.hashCode() = "+em3.hashCode());
        System.out.println("em4.hashCode() = "+em4.hashCode());//we can see how the same object returns the same hash, even though
        //the hashCode function was invoked via different links.

        String s1 = "hi there";
        String s2 = "hi there";
        String s3 = "hi theri";
        System.out.println("s1.hashCode() = "+s1.hashCode());//The String class has its own method for calculating the hash.
        System.out.println("s2.hashCode() = "+s2.hashCode());//That's why these two hashes are equal, even though these objects are in two different memory parts
        System.out.println("s3.hashCode() = "+s3.hashCode());





}
}
