#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>
#include <iostream>
#include <Windows.h>
#include <fstream>
using namespace std;

main()
{
SetConsoleOutputCP(1251);
SetConsoleCP(1251);
char  b[500];
int n,i,j,k=50,m;
FILE *text, *glas, *sogl, *nov;
cout <<"Введите колличество строк"<<endl;
scanf("%d",&n);
text=fopen("текст.txt","w");
int t=0;
int pop[50];
char a[n];
char rt;
nov=fopen("Наоборот.txt","wt");
j=0;
for(i=0;i<=n;i++)
{
	gets(a);
	fprintf(text,"%s\n",a);
}
i=0;
fclose(text);
text=fopen("текст.txt","r");
glas=fopen("гласные.txt","w");
sogl=fopen("согласные.txt","w");
j=n;
char p;
p=' ';
int e;
while (!feof(text))                                  
{ 
	m=getc(text);                          
     if((m==225)||(m==226)||(m==227)||(m==228)||(m==230)||(m==231)||(m==234)||(m==235)||(m==236)||(m==237)||(m==239)||(m==240)||(m==241)||(m==242)||(m==244)||(m==245)||(m==246)||(m==247)||(m==248)||(m==249)||(m==250)||(m==252)||(m==233))
		{
			for(i=0;i<k;i++)
			{
			if ((m==32)||(m=='/0')) { e++; break;}
			else
			{putc(m,sogl);  
			pop[j];
			j--;
			m=getc(text);
			e++; }
			}
			
	putc(p,sogl);
		}
	 else if((m==224)||(m==229)||(m==232)||(m==238)||(m==243)||(m==253)||(m==254)||(m==255))
		{ 
			for(i=0;i<k;i++)
			{
			if ((m==32)||(m=='/0')){t++; break;}
			else
			{putc(m,glas);   
			m=getc(text);
		t++;
			}
			}
	putc(p,glas);
		}    
} 
cout<<endl<<"Согласные"<<endl;
fclose(sogl);                         
rewind(sogl);
sogl=fopen("согласные.txt","r");   
 for(i=0;i<e;i++)                 
  {  m=getc(sogl);                  
      putchar(m);             
   }
 

cout<<endl<<"Гласные"<<endl;		
fclose(glas);                         
rewind(glas);
glas=fopen("гласные.txt","r");   

 for(i=0;i<t;i++)                  
  { 
  	m=getc(glas);                  
    putchar(m); 	                   
   }

int l;
rewind(text);
while(!feof(text))
{
	l=getc(text);
	b[i]=l;
	i++;
}
fclose(text); 
int d;

for(d=i-2;d>-1;d--)
{
	
	putc(b[d],nov);
}

cout<<endl<<"Наоборот"<<endl;		
fclose(nov);                         
rewind(nov);
nov=fopen("Наоборот.txt","r");   
 for(i=0;i<e+t+4;i++)                 
  {  m=getc(nov);                  
      putchar(m);             
   }
  
	
fclose(text); 
fclose(sogl); 

fclose(nov); 
	
getch();
}
