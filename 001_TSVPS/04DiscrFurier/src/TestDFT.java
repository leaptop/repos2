public class TestDFT {//https://pdfs.semanticscholar.org/73e4/ab8eaed9e9cba7e4f375e685f17f9ae0bbb5.pdf?_ga=2.246286660.172059643.1562748583-1182672405.1562748583
    public static void main(String args[]) {
        int N = 64;
        double T = 2.0;
        double tn, fk;
        double fdata[] = new double[2*N];
        for(int i=0; i<N; ++i) {
            fdata[2*i] = Math.cos(4.0*Math.PI*i*T/N);
            fdata[2*i+1] = 0.0;
        }
        double X[] = Fourier.discreteFT(fdata, N, true);
        for (int k=0; k<N; ++k) {
            fk = k/T;
            System.out.println("f["+k+"] = "+fk+"Xr["+k+"] = "+X[2*k]+ " Xi["+k+"] = "+X[2*k + 1]) ;
        }
        for (int i=0; i<N; ++i) {
            fdata[2*i] = 0.0;
            fdata[2*i+1] = 0.0;
            if (i == 4 || i == N-4 ) {
                fdata[2*i] = 0.5;
            }
        }
        double x[] = Fourier.discreteFT(fdata, N, false);
        System.out.println();
        for (int n=0; n<N; ++n) {
            tn = n*T/N;
            System.out.println("t["+n+"] = "+tn+"xr["+n+"] = "+x[2*n]+" xi["+n+"] = "+x[2*n + 1]);
        }
    }
}