public class A {//класс вложенный внутрь объекта Main д.б. статическим
    private int i = 1;

    public void f() {
        int i;//НЕ МОГУ ПОЙМАТЬ ЛОКАЛЬНУЮ ПЕРЕМЕННУЮ... В СМЫСЛЕ ЧТОБЫ ЕЁ БЫЛО ВИДНО В КАКОМ-НИБУДЬ ОКНЕ INTELLIJ
        int bbb = 11;
        bbb++;
        System.out.println("bbb = " + bbb);//ошибка компиляции(i не инициализирована)
        //1
        try {
            System.out.println("inside A\n");
            Thread.sleep(10000000);
        }catch (Exception e){}
    }
}