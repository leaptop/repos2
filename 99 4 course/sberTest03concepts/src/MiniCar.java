public class MiniCar extends Car     {

    public MiniCar(){

        this.color = "red";
        //super();
    }

    public static void main(String[] args) {
        MiniCar mc = new MiniCar();
        System.out.println(mc.color);
    }
}
