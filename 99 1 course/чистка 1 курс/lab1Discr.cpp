#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <locale.h>
#include <string.h>
#include <conio.h>


using namespace std;
main()
{
setlocale(LC_ALL,"Rus");
int a,b,i,c;
cout<<"number of elements À=";
scanf("%d",&a);
cout<<"number of elements B=";
scanf("%d",&b);
char A[a], B[b],C[b], M[a],P[a];
L:
system("cls");
cout<<"À: ";
for (i=0;i<a*2;i++)
{
	 scanf("%c",&A[i]);
	 
}
for(i=0;i<a*2;i++) { if((A[i]=='1')||(A[i]=='2')||(A[i]=='3')||(A[i]=='4')||(A[i]=='5')||(A[i]=='6')||(A[i]=='7')||(A[i]=='8')||(A[i]=='9')||(A[i]=='0')||(A[i]=='!')||(A[i]=='@')||(A[i]=='#')||(A[i]=='$')||(A[i]=='%')||(A[i]=='^')||(A[i]=='&')||(A[i]=='*')||(A[i]=='(')||(A[i]==')')||(A[i]=='"')||(A[i]=='¹')||(A[i]==';')||(A[i]==':')||(A[i]=='?')||(A[i]=='`')||(A[i]=='~')||(A[i]=='-')||(A[i]=='_')||(A[i]=='+')||(A[i]=='=')||(A[i]=='[')||(A[i]==']')||(A[i]=='{')||(A[i]=='}')||(A[i]=='/')||(A[i]=='|')||(A[i]=='.')||(A[i]=='>')||(A[i]==',')||(A[i]=='<')||(A[i]=='à')||(A[i]=='á')||(A[i]=='â')||(A[i]=='ã')||(A[i]=='ä')||(A[i]=='å')||(A[i]=='¸')||(A[i]=='æ')||(A[i]=='ç')||(A[i]=='è')||(A[i]=='é')||(A[i]=='ê')||(A[i]=='ë')||(A[i]=='ì')||(A[i]=='í')||(A[i]=='î')||(A[i]=='ï')||(A[i]=='ð')||(A[i]=='ñ')||(A[i]=='ò')||(A[i]=='ó')||(A[i]=='ô')||(A[i]=='õ')||(A[i]=='ö')||(A[i]=='÷')||(A[i]=='ø')||(A[i]=='ù')||(A[i]=='ú')||(A[i]=='û')||(A[i]=='ü')||(A[i]=='ý')||(A[i]=='þ')||(A[i]=='ÿ')) { goto L;}}
				

for (i=0;i<a*2;i++)
{
	 M[i]=A[i];
}

puts("\n");
K:
cout<<"B: ";
for (i=0;i<b*2;i++)
{
	 scanf("%c",&B[i]);
}
for (i=0;i<b*2;i++)
{
	 C[i]=B[i];
}
for(i=0;i<a*2;i++) { if((B[i]=='1')||(B[i]=='2')||(B[i]=='3')||(B[i]=='4')||(B[i]=='5')||(B[i]=='6')||(B[i]=='7')||(B[i]=='8')||(B[i]=='9')||(B[i]=='0')||(B[i]=='!')||(B[i]=='@')||(B[i]=='#')||(B[i]=='$')||(B[i]=='%')||(B[i]=='^')||(B[i]=='&')||(B[i]=='*')||(B[i]=='(')||(B[i]==')')||(B[i]=='"')||(B[i]=='¹')||(B[i]==';')||(B[i]==':')||(B[i]=='?')||(B[i]=='`')||(B[i]=='~')||(B[i]=='-')||(B[i]=='_')||(B[i]=='+')||(B[i]=='=')||(B[i]=='[')||(B[i]==']')||(B[i]=='{')||(B[i]=='}')||(B[i]=='/')||(B[i]=='|')||(B[i]=='.')||(B[i]=='>')||(B[i]==',')||(B[i]=='<')||(B[i]=='à')||(B[i]=='á')||(B[i]=='â')||(B[i]=='ã')||(B[i]=='ä')||(B[i]=='å')||(B[i]=='¸')||(B[i]=='æ')||(B[i]=='ç')||(B[i]=='è')||(B[i]=='é')||(B[i]=='ê')||(B[i]=='ë')||(B[i]=='ì')||(B[i]=='í')||(B[i]=='î')||(B[i]=='ï')||(B[i]=='ð')||(B[i]=='ñ')||(B[i]=='ò')||(B[i]=='ó')||(B[i]=='ô')||(B[i]=='õ')||(B[i]=='ö')||(B[i]=='÷')||(B[i]=='ø')||(B[i]=='ù')||(B[i]=='ú')||(B[i]=='û')||(B[i]=='ü')||(B[i]=='ý')||(B[i]=='þ')||(B[i]=='ÿ')) { goto K;}}
puts("\n");
M:
puts("\n");
cout<< "1. show sets À è B"<<endl;
cout<< "2. À U B"<<endl;
cout<< "3. intersection À and Â"<<endl;
cout<< "4. A without B"<<endl;
cout<< "5. B without À"<<endl;
cout<< "6. Symmetric difference À and Â"<<endl;
cout<< "0. Out"<<endl;

int p,j,k;
char t;

p=getch();
switch (p)
{
	case '1': system("cls");
				cout<<"À: ";for(i=1;i<a*2;i++){printf("%c",M[i]);}
				puts("\n");
				cout<<"Â: "; for(i=1;i<b*2;i++){printf("%c",C[i]);}
				puts("\n");
				cout<<"0. Return to menu";
				c=getch();
				if (c=='0') system("cls"); goto M;
	case '2': system("cls");
	for(i=1;i<a*2;i++) {A[i]=M[i];}
	for(i=1;i<b*2;i++) {B[i]=C[i];}
				for(i=0;i<a*2;i++)
				{
					t=A[i];
					for(j=b*2;j>0;j--)
					{
						if(A[i]==B[j]) B[j]=0;
						
					}
				}
				
				for (i=1;i<a*2;i+=2){printf("%c",A[i]); cout << " ";}
				for (i=1;i<b*2;i+=2){if(B[i]!=0) printf("%c",B[i]); cout << " ";}
				puts("\n");
				cout<<"0. Return to menu";
				c=getch();
				if (c=='0') system("cls"); goto M;
	case '3': system("cls");
	for(i=1;i<a*2;i++) {A[i]=M[i];}
	for(i=1;i<b*2;i++) {B[i]=C[i];}
				for(i=0;i<a*2;i++)
				{
					t=A[i];
					for(j=b*2;j>0;j--)
					{
						if(A[i]==B[j]) P[j]=A[i];
						
					}
				}
				
				for (i=1;i<((a*2))-1;i++){printf("%c",P[i]); cout << " ";}
				
				puts("\n");
				cout<<"0. Return to menu";
				c=getch();
				if (c=='0') system("cls"); goto M;
	case '4': system("cls");
	for(i=1;i<a*2;i++) {A[i]=M[i];}
	for(i=1;i<b*2;i++) {B[i]=C[i];}
				for(i=0;i<a*2;i++)
				{
					t=A[i];
					for(j=b*2;j>0;j--)
					{
						if(A[i]==B[j]) A[i]=0;
						
					}
				}
				
				for (i=1;i<a*2;i++){printf("%c",A[i]); cout << " ";}
				puts("\n");
				cout<<"0. Return to menu";
				c=getch();
				if (c=='0') system("cls"); goto M;
	case '5':system("cls");
	for(i=1;i<a*2;i++) {A[i]=M[i];}
	for(i=1;i<b*2;i++) {B[i]=C[i];}
				for(i=0;i<a*2;i++)
				{
					t=A[i];
					for(j=b*2;j>0;j--)
					{
						if(A[i]==B[j]) B[j]=0;
						
					}
				}
			//	for (i = 0; i<b*2; i++){if (B[i]== 0) for(int j = i; j<b*2-1; j++)B[j]=B[j+1];}
				for (i=0;i<b*2;i++){printf("%c",B[i]); cout << " ";}
				puts("\n");
				cout<<"0. Return to menu";
				c=getch();
				if (c=='0') system("cls"); goto M;
	case '6': system("cls");
	for(i=1;i<a*2;i++) {A[i]=M[i];}
	for(i=1;i<b*2;i++) {B[i]=C[i];}
				for(i=0;i<a*2;i++)
				{
					t=A[i];
					for(j=b*2;j>0;j--)
					{
						if(A[i]==B[j]) {A[i]=0; B[j]=0;}
						
					}
				}
				
				for (i=1;i<a*2;i+=2){printf("%c",A[i]); cout << " ";}
				for (i=1;i<b*2;i++){ printf("%c",B[i]); }
				
				puts("\n");
				cout<<"0. Return to menu";
				c=getch();
				if (c=='0') system("cls"); goto M;
			
	case '0': break;			
	default: system("cls"); cout<<"Error"; goto M;
				
			
}	
	
	
system("PAUSE");
}


