#include <stdio.h>
#include <math.h>
#include <conio.h>
#include <iostream>
//#define y2 (pow(2.7,x)+Y[0])/2
#define y2 x*Y[0]+Y[1]
const int n=2;
using namespace std;
double* F(double x,double* Y){
	double *y=new double[n];
	y[0]=Y[1];
	y[1]=y2;
	//cout<<endl<<Y[0]<<Y[1]<<endl;
	return y;
}

double* summ(double* Y,double* k,double h){
	double *y=new double[n];
	for(int i=0;i<n;i++){
		y[i]=Y[i]+(h*k[i]);
	}
	return y;
}

double* Yi(double* Y,double x,double h){
	double **k=new double*[4];
	//double *K=new double[n];
	for(int i=0;i<n;i++){
		k[i]= new double[n];
	}
	k[0]=F(x,Y);
	k[1]=F(x+(h/2),summ(Y,k[0],h/2));
	k[2]=F(x+(h/2),summ(Y,k[1],h/2));
	k[3]=F(x+(h),summ(Y,k[2],h));
	
//	for(int i=0;i<4;i++){
//		cout<<"|"<<k[i][0]<<"|"<<endl<<"|"<<k[i][1]<<"|"<<endl<<endl;
//	}
	return summ(Y,summ(summ(k[0],k[1],2),summ(k[3],k[2],2),1),h/6);
}

int main()
{
	
	double y=2,y1=4,x=1 ,e, h,b ,*Y=new double[n], *nY=new double[n], *nnY=new double[n];
	Y[0]=nY[0]=1;
	Y[1]=nY[1]=-1;
	x=1;
	h=0.2;
	e=0.000001;
	b=2;
	int c=0;
	do{
	Y[0]=nY[0]=1;
	Y[1]=nY[1]=-1;
		cout<<"H="<<h<<"____________________"<<endl;

		int n=(int)(b-x)/h;
		
		for(int i=0;i<=n;i++){	
		Y=Yi(Y,x+(h*i),h);
		cout<<"x="<<x+(h*i)<<"\t|"<<Y[0]<<"|"<<endl<<"\t|"<<Y[1]<<"|"<<endl<<endl;
	}
	
		h=h/2;
		n=(int)(b-x)/h;
		for(int i=0;i<=n;i++){
			nY=Yi(nY,x+(h*i),h);
			cout<<"x1="<<x+(h*i)<<"\t|"<<nY[0]<<"|"<<endl<<"\t|"<<nY[1]<<"|"<<endl<<endl;
		}
		c++;
		h=h/2;
	}while(fabs((Y[0]-nY[0]))>=e);
	
//	for(double i=x;i<=2;i+=(h/2)){
//		Y=Yi(Y,i,h/2);
//cout<<"x="<<i<<"\t|"<<Y[0]<<"|"<<endl<<"\t|"<<Y[1]<<"|"<<endl<<endl;
//}

	
	cout<<"c="<<c;;
}
