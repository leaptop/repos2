#include <iostream>
#include <graphics.h>
 #include "math.h"
 #include <stdio.h>
using namespace std;
struct complexNumber{
	double Re;
	double Im;
}a,b,c;
complexNumber multiplicationComlx(complexNumber a, complexNumber b){
	complexNumber number;
	number.Re=(a.Re*b.Re-(a.Im*b.Im));
	number.Im=(b.Re*a.Im+(a.Re*b.Im));
	return  number;
}

complexNumber Interp_Trigm(double x,double* x0, double* y0, int n, int h){
	complexNumber	*a=new complexNumber[n],summ,rez;
	//,*b=new double[n];

	for(int i=0;i<n;i++){
		a[i].Im=0;
		a[i].Re=0;
		for(int j=0;j<n;j++){
			a[i].Re+=y0[j]*cos(-2*3.14*(i-((int)(n/2)-1))*j/n);
			a[i].Im+=y0[j]*sin(-2*3.14*(i-((int)(n/2)-1))*j/n);
			cout<<a[i].Re<<"+"<<a[i].Im<<"i"<<endl;
		}
	}
	cout<<"-------------------------------";
	rez.Re=0; rez.Im=0;
	for(int i=0;i<n;i++){
		summ.Re=cos(2*3.14*(i-((int)(n/2)-1))*(x-x0[0])/n/h);
		summ.Im=sin(2*3.14*(i-((int)(n/2)-1))*(x-x0[0])/n/h);
		summ=multiplicationComlx(a[i],summ);
		rez.Re+=summ.Re/n;
		rez.Im+=summ.Im/n;
		cout<<(i-(ceil(n/2)-1))<<"-"<<rez.Re<<"+"<<rez.Im<<"i"<<endl;
	}

	return rez;
}


int main()
{
	a.Im=-1; a.Re=1;
	b.Im=6; b.Re=3;
	c=multiplicationComlx(a,b);
	cout<<c.Re<<"+"<<c.Im<<"i";

	int n;
	double x,h;
	cout<<"n=";
	cin>>n;
	double	*x0=new double[n],*y0=new double[n];
	cout<<endl<<"x=";
	cin>>x;

	cout<<endl<<"x0=";
	cin>>x0[0];
	cout<<x0[0];
	cout<<endl<<"h=";
	cin>>h;
	for(int i=1;i<n;i++){
        x0[i]=x0[i-1]+h;
       // cout<<x0[i];
	}
	for(int i=0;i<n;i++){

       y0[i]=(1/pow(x0[i],0.5));
       //cout<< y0[i];
	}
c=Interp_Trigm(x, x0,y0, n,h);
cout<<c.Re<<"+"<<c.Im<<"i";


initwindow(1500,600);
moveto(30,30);
lineto(30,450);
lineto(800,450);
moveto(30,450);

for(double i=0;i<=800;i+=0.01)         // ?????? ? ????? (0,0)
lineto(i*100+30,450-(1/pow(i,0.5)*100));
moveto(x0[0]*100+30,450-y0[0]*100);

 setcolor(RED);

for(double i=x0[0];i<=x0[n-1];i+=0.01)         // ?????? ? ????? (0,0)
lineto(i*100+30,450-Interp_Trigm(i, x0,y0, n,h).Re*100);
moveto(x0[0]*100+30,450-y0[0]*100);
 setcolor(GREEN);
for(double i=x0[0];i<=x0[n-1];i+=0.01)
lineto(i*100+30,450-Interp_Trigm(i, x0,y0, n,h).Im*100);
    char buff [100];


for(int i=0;i<n;i++){
    circle(x0[i]*100+30,450-y0[i]*100,4);
sprintf (buff, "(%.2f ; %.2f)",  x0[i], y0[i]);
    outtextxy(x0[i]*100+30, 450-y0[i]*100+30, buff);
}

getch();
closegraph();


}



