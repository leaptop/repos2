

class BusinessException extends Exception {
    BusinessException(int ff){
        num = ff;
    }
    int num = 4;
    public void meth(){
        System.out.println("inside the exception. parameter = " + num);
    }
}