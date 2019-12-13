
#include <iostream>
 #include "math.h"
 #include <stdio.h>
using namespace std;

double Interp_Trigm(double x,double* x0, double* y0, int n, int h){
	double	*a=new double[n],*b=new double[n];
	double summ=0;
	for(int i=1;i<n;i++){
		summ=0;
		for(int j=0;j<n;j++)
			summ+=(y0[j]*sin(2*3.14*j*i/(n)));
		a[i]=summ/n;
		cout<<a[i]<<endl;
	}#include <graphics.h>

#include <iostream>
 #include "math.h"
 #include <stdio.h>
using namespace std;

double Interp_Trigm(double x,double* x0, double* y0, int n, int h){
	double	*a=new double[n],*b=new double[n];
	double summ=0;
	for(int i=1;i<n;i++){
		summ=0;
		for(int j=0;j<n;j++)
			summ+=y0[j]*sin(2*3.14*j*i/n);
		a[i]=summ/n;
	}

	for(int i=0;i<n;i++){
		summ=0;
		for(int j=0;j<n;j++)
			summ+=y0[j]*cos(2*3.14*j*i/n);
		b[i]=summ/n;
	}
	summ=0;
	for(int i=1;i<n;i++){
		summ+=(b[i]*cos(2*3.14*i*(x-x0[0])/n/h))+(a[i]*sin(2*3.14*i*(x-x0[0])/n/h));
	}
	return b[0]+summ;
}


int main()
{
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


cout<<endl<<Interp_Trigm(x, x0,y0, n,h);

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
lineto(i*100+30,450-Interp_Trigm(i, x0,y0, n,h)*100);
    char buff [100];


for(int i=0;i<n;i++){
    circle(x0[i]*100+30,450-y0[i]*100,4);
sprintf (buff, "(%.2f ; %.2f)",  x0[i], y0[i]);
    outtextxy(x0[i]*100+30, 450-y0[i]*100+30, buff);
}

getch();
closegraph();


//cout<<endl <<Interp_lograng(x, x0, y0, n);
}


	for(int i=1;i<n;i++){
		summ=0;
		for(int j=0;j<n;j++)
			summ+=(y0[j]*cos(2*3.14*j*i/(n)));
		b[i]=summ/(n-1);
		cout<<a[i]<<endl;
	}
	
		summ=0;
		for(int j=0;j<n;j++)
			summ+=y0[j];
		b[0]=summ/(n);
		cout<<b[0]<<endl;
	
	summ=0;
	for(int i=1;i<n;i++){
		summ+=(b[i]*cos(2*3.14*i*(x-x0[0])/(n)/h))+(a[i]*sin(2*3.14*i*(x-x0[0])/(n)/h));	
	}
	return b[0]+summ;
}


int main()
{
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
       cout<< y0[i];
	}


cout<<endl<<Interp_Trigm(x, x0,y0, n,h);

//initwindow(1500,600);
//moveto(30,30);
//lineto(30,450);
//lineto(800,450);
//moveto(30,450);
//
//for(double i=0;i<=800;i+=0.01)         // ?????? ? ????? (0,0)
//lineto(i*100+30,450-((2*pow(i,3)-2*pow(i,2)+3*i-1)*100));
//moveto(x0[0]*100+30,450-y0[0]*100);
//
// setcolor(RED);
//
//for(double i=x0[0];i<=x0[n-1];i+=0.01)         // ?????? ? ????? (0,0)
//lineto(i*100+30,450-Interp_Newton(i, x0,y0, n,h)*100);
//    char buff [100];
//
//
//for(int i=0;i<n;i++){
//    circle(x0[i]*100+30,450-y0[i]*100,4);
//sprintf (buff, "(%.2f ; %.2f)",  x0[i], y0[i]);
//    outtextxy(x0[i]*100+30, 450-y0[i]*100+30, buff);
//}
//
//getch();
//closegraph();


//cout<<endl <<Interp_lograng(x, x0, y0, n);
}

