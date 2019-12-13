public class TestFFT {//https://pdfs.semanticscholar.org/73e4/ab8eaed9e9cba7e4f375e685f17f9ae0bbb5.pdf?_ga=2.246286660.172059643.1562748583-1182672405.1562748583
    public static void main(String args[ ]) {
        int N = 64;
        double T = 1.0;
        double tn, fk;
        double fdata[ ] = new double[2*N];
        for(int i=0; i<N; ++i) {
            fdata[2*i] = Math.cos(8.0*Math.PI*i*T/N) +
                    Math.cos(14.0*Math.PI*i*T/N) +
                    Math.cos(32.0*Math.PI*i*T/N);
            fdata[2*i+1] = 0.0;
        }
        Fourier.fastFFT(fdata, N, true);
        System.out.println();
        for(int k=0; k<N; ++k) {
            fk = k/T;
            System.out.println( "f["+k+"] = " + fk + " Xr["+k+"] = " + fdata[2*k] + " Xi["+k+"] = " + fdata[2*k+1]) ;
        }
    }
}
