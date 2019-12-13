#include <stdio.h>
#include <math.h>
#include <conio.h>
#include <iostream>
//#define y2 (exp(x)+Y[0])/2
//#define y2 exp(x)+Y[1]
#define y2 exp(x)+Y[1]
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
bool comparison(double** y, double** yy,int N,double e){
	bool t=false;
	for(int i=0;i<=N;i+=2){
		if(fabs((y[i/2][1]-yy[i][1]))<15*e){
		//	cout<<"!";
			t= true;	
		}	
		else return false;
			
	}
	return t;
}

int main()
{
	
	double x=1 ,e, h,b,**yy,**y,*Y=new double[n], *nY=new double[n];
	int nn;
	x=0;
	h=0.2;
	e=0.0000001;
	b=1;
	int c=0;
	do{
	Y[0]=nY[0]=1;
	Y[1]=nY[1]=0.42;
	
	cout<<"H="<<h<<""<<endl;

		nn=(int)((b-x)/h);
		cout<<nn;
		
		y=new double *[nn+1];
		for(int i=0;i<=nn;i++){
		y[i]= new double[n];
	}
		y[0]=Y;
		printf("x=%f y=|%10.10f| y'=|%10.10f|\n",x,y[0][0],y[0][1]);
		for(int i=1;i<=nn;i++){	
		Y=Yi(Y,x+(h*i)-h,h);
		y[i]=Y;
	//	cout<<"x="<<x+(h*i)<<"\t|"<<Y[0]<<"  |"<<"\t|"<<Y[1]<<"|"<<endl<<endl;
		printf("x=%f y=|%10.10f| y'=|%10.10f|\n",x+(h*i),y[i][0],y[i][1]);
		
	}
	
		h=h/2;
		cout<<"H="<<h<<"____________________"<<endl;
		nn=(int)((b-x)/h);
		
		yy=new double *[nn+1];
		for(int i=0;i<nn;i++){
		yy[i]= new double[n];
	}
		yy[0]=nY;
		printf("x=%f y=|%10.10f| y'=|%10.10f|\n",x,yy[0][0],yy[0][1]);
		for(int i=1;i<=nn;i++){
			nY=Yi(nY,x+(h*i)-h,h);
			yy[i]=nY;
		//	cout<<"x1="<<x+(h*i)<<"\t|"<<nY[0]<<"  |"<<"\t|"<<nY[1]<<"|"<<endl<<endl;
			printf("x=%f y=|%10.10f| y'=|%10.10f|\n",x+(h*i), yy[i][0],yy[i][1]);
		}
		c++;
		h=h/2;
	}while(!comparison(y,yy,nn,e));
	
//	for(double i=x;i<=2;i+=(h/2)){
//		Y=Yi(Y,i,h/2);

printf("\nx=%f y=|%10.10f| y'=|%10.10f|\n",x, nY[0],nY[1]);
//}
delete[]yy;
	delete[]y;
	
	cout<<"c="<<c;;
}
