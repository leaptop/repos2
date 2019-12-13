
class LagrInter {

    public static void main(String[] args) {

        int n = 3;
        float[] xx = new float[200];
        float[] yy = new float[200];
        float x = 12;
        float y = 0;
        xx[0] = 5;
        xx[1] = 10;
        xx[2] = 20;
        yy[0] = 12;
        yy[1] = 25;
        yy[2] = 18;
        float chisl;
        float znam;

        for (int i = 0; i < n; i++) {// здесь i - номер избегаемой переменной
            chisl = 1;
            znam = 1;
            for (int j = 0; j < n; j++) {
                if (i != j) {
                    chisl *= (x - xx[j]);
                    znam *= (xx[i]-xx[j]);
                }
            }
            y += (chisl *= (yy[i])) / znam;
        }
        System.out.println("Если x = " + x + ", то" + " y = " + y);
    }
}
