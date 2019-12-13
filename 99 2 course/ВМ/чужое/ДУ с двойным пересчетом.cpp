#include <math.h>
#include <stdlib.h>
#include <conio.h>
#include <graphics.h>
#include <conio.h>
#include <cmath>
#include <iostream> 
#include <iomanip> 

#define E 0.00000001

using namespace std;

double shag(double h, double x, double y[]){
       
       double zy[2];
       double ry[2];

       ry[0]=y[0];
       ry[1]=y[1];
    
       
       for(int j=0; j<2; j++){
        if(j==0){
        zy[j]=y[j]+h/2*(y[1]);
        }
        else{
        zy[j]=y[j]+h/2*((exp(x)+y[0])/2);
             }
        }

        for(int q=0; q<2; q++){
        if(q==0){
        ry[q]=y[q]+h*(zy[1]);
        }
        else{
        ry[q]=y[q]+h*((exp(x+h/2)+zy[0])/2);
            }
        }
    
    y[0]=ry[0];
    y[1]=ry[1];
    return y[0], y[1];
       }
//---------------------------------------------------------------

double shag1(double h, double x, double y[]){
       
       double zy[2];
       double ry[2];

       ry[0]=y[0];
       ry[1]=y[1];
         
       for(int j=0; j<2; j++){
        if(j==0){
        zy[j]=y[j]+h/2*(y[1]);
        }
        else{
        zy[j]=y[j]+h/2*((exp(x)+y[0])/2);
             }
        }

        for(int q=0; q<2; q++){
        if(q==0){
        ry[q]=y[q]+h*(zy[1]);
        }
        else{
        ry[q]=y[q]+h*((exp(x+h/2)+zy[0])/2);
            }
        }
    
    y[0]=ry[0];
    y[1]=ry[1];
    return y[0], y[1];
       }


//---------------------------------------------------------------

int main(){

double h=0.2;

double k=1;

double h1; 
double h2;

double x1;
double y1[2];

double x2;
double y2[2];

double b;
double a1;
double a2;

b=1;

double *mass1;
double *mass2;


int kol=0;
int f=0;
//-------------------------------------------------

do{

x1=0;
y1[0]=1;
y1[1]=k;

x2=0;
y2[0]=1;
y2[1]=k;

mass1 = (double*)malloc((b/h+1) * sizeof(double));
mass2 = (double*)malloc((b/(h/2)+1) * sizeof(double));

//-----------
for(int i=0; i<b/h+1; i++)
{
mass1[i]=y1[0];     
shag(h, x1, y1);
x1+=h;
}

//-----------
for(int i=0; i<b/(h/2)+1; i++)
{

mass2[i]=y2[0];
                     
shag(h/2, x2, y2);

x2+=h/2;
}

for(int i=1; i<b/h+1; i++){
        if(fabs(mass1[i]-mass2[i*2])<3*E){
                                kol=1;
                                f=i;
                                break;        
                                        }        
}

if(kol==1){
           break;
           }
h=h/2;

free(mass1);
free(mass2);
}while(fabs(y1[0]-y2[0])>3*E);

//-----------
//-------------------------------------------------------
int size=b/(h/2)+1;

double massX[size];
double massY[size];
double massY1[size];

//-------------------------------------------------


double xx=0;
double yy[2];
yy[0]=1;
yy[1]=k;

for(int i=0; i<b/(h/2)+1; i++)
{
massX[i]=xx;
massY[i]=yy[0];
massY1[i]=yy[1];                
shag(h/2, xx, yy);
xx+=h/2;
}
cout<<"\tX"<<"\t  Y"<<"\t  Y'\n"<<endl<<endl;


for(int i=0; i<b/(h/2)+1; i++){
cout<<"\n  "<<massX[i]<<fixed<<setprecision(8)<<"\t  "<<massY[i]<<"\t  "<<massY1[i]<<endl<<endl;

} 

//-------------------------------------------------------

system("PAUSE");    
return 0;   
}
