public class AA {
    //public void m(String... args){   }//TestserAA не компилируется, т.к. список параметров, переданный в функцию не соответствует
    public void m(Object... str){
        System.out.println("first argument = " + str[0] +", second = "+str[1]+", third = "+str[2]);
    }
}
