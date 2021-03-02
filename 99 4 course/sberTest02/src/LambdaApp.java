public class LambdaApp {
    public static void main(String[] args) {//this is a way of using lambda's to create objects
        UserBuilder userBuilder = User::new;//declared, that our lambda will instantiate User type objects
        User user = userBuilder.create("Tom");//declared a User variable user and attached a newly created object to it
        System.out.println(user.getName());//but how does it understand, that the String should become a parameter
        //for the constructor? Apparently it's implemented in this kind of lambda usage.
    }
}
