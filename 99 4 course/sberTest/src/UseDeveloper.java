public class UseDeveloper /*implements Developer*/{//if you declare the class implementing Developer, the bug will be: you have to
    // implement method writecode()

                                    //THIS IS THE CORRECT WAY OF USING OF LAMBDA EXPRESSION. It all works.
    public void writeCode() {
        System.out.println("some code");
    }

    public static void main(String[] args) {
        String devName = "Petrov";//if you declare devName as final, it won't do anything
        Developer dev = () ->
                System.out.println("Writing java code by " + devName);
        dev.writeCode();
    }
}//короче программа не вызывает ошибок, выводится Writing java code by Petrov

//        UseDeveloper ud = new UseDeveloper();
//        ud.writeCode();
//        System.out.println("or else");