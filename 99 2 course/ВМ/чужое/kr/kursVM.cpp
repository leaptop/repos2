#include <stdio.h>
#include <math.h>
#include <conio.h>
#include <iostream>
//#define y2 (exp(x)+Y[0])/2
//#define y2 x*Y[0]+Y[1]
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
	for(int i=0;i<=N;i+=2){
		if(fabs((y[i/2][1]-yy[i][1]))>=15*e)
		return false;
			
	}
	return true;
}
double* Yi(double* Y1,double x,double h, int b,double e){
	double  c=0,*Y=new double[n], *nY=new double[n],**y,**yy;
	int nn;
		do{
	Y[0]=nY[0]=Y1[0];
	Y[1]=nY[1]=Y1[1];
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
	return yy[nn];
}
double searchCor(double* Y,double x,double h, int b,double e){
	double l,ll,c,temp, *y=new double[n],*yy=new double[n];
	ll=l=atan((Y[1]-Y[0])/(b-x));
	//cout<<ll<<endl;
	do{			
		y[1]=ll;
		y[0]=Y[0];	
		//cout<<ll<<";"<<Y[0]<<endl;		
		y=Yi(y, x, h,b,e);
		
			 if(y[0]<Y[1])
			ll+=e;
				else if(y[0]>Y[1])
				ll-=e;
			//	cout<<y[1]<<";"<<Y[1]<<endl;
	}while(fabs(y[0]-Y[1])>e);
	
if(l>ll){
	temp=l;
	l=ll;
	ll=temp;
}
cout<<l<<";"<<ll<<endl;
do{
	cout<<l<<";"<<ll<<endl;
	c=(l+ll)/2;

	yy[1]=l;
	y[1]=c;
	yy[0]=y[0]=Y[0];
		if((Yi(y, x, h,b,e)[0]-Y[1])*(Yi(yy, x, h,b,e)[0]-Y[1]) < 0)
		ll=c;
		else
		l=c;	
	
}while((yy[0]-Y[1])>=e);
cout<<"h="<<c;	
	return yy[1];
}
int main()
{
	
	double y=2,y1=4,x=1 ,e, h , a=0, *Y=new double[n], *nY=new double[n], *nnY=new double[n], *nnnY=new double[n];
	int b;
	x=0;
	h=0.2;
	e=0.01;
	b=1;
	Y[0]=nY[0]=0;
	Y[1]=2.71828;
	nY[1]=searchCor(Y,x,h, b,e);
	cout<<"Y'="<<nY[1]<<endl<<"Reshenie ZK:"<<endl;
	nY=Yi(nY, x, h,b,e);
//	cout<<"\t|"<<nY[0]<<"|"<<endl<<"\t|"<<nnnY[1]<<"|"<<endl<<endl;




}
