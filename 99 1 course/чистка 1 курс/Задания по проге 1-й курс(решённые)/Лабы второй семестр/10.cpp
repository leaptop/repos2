#include <stdio.h>
#include <conio.h>
#include <clocale>
#include <stdlib.h>
#include <windows.h>
#include <string.h>
using namespace std;
main(){
	char bufer[1000], Exit[1000],ch; int i,n;
	FILE *po, *ptw, *ptr, *pf;
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	printf("¬ведите кол-во строк "); scanf("%d",&n);
	printf("\n ¬водите \n"); po=fopen("new1.txt","wt");
	for (i=-1; i<n; i++){
		gets(bufer);
		//fread(bufer, 1,strlen(bufer),po);
		fprintf(po,"%s\n",bufer);
	} 
	fclose(po); po=fopen("new1.txt","rt");  rewind(po);
//	fgets(Exit,1000,po); puts(Exit);
	ptw=fopen("new2.txt","wt"), ptr=fopen("new3.txt","wt"); int g=0, h=0;
	ch=getc(po); char ty=' ';
	while (!feof(po)){ 
		if (ch!=' ') {
			if ((ch=='a')or(ch=='i')or(ch=='e')or(ch=='o')or(ch=='y')) {
				while(ch!=' '&&!feof(po)) putc(ch,ptw), ch=getc(po),g++;
				putc(ty,ptw);
			}
			else {while(ch!=' '&&!feof(po)) putc(ch,ptr),ch=getc(po),h++;
			putc(ty,ptr);}
		}
		else ch=getc(po);
	}
	fclose(ptw); fclose (ptr); 
	ptw=fopen("new2.txt","rt");  rewind(ptw); printf("\n"); 
	while (!feof(ptw)) ch=getc(ptw), putchar(ch);
	   fclose(ptw);
	   ptr=fopen("new3.txt","rt");rewind(ptr); printf("\n");
	while (!feof(ptr)) ch=getc(ptr), putchar(ch); 
	fclose (ptr); printf("\n");
	po=fopen("new1.txt","rt"); g=0;
		while (!feof(po)) ch=getc(po), Exit[g]=ch, g++;
	for (i=g-1; i>-1; i--) printf("%c",Exit[i]);	
	pf=fopen("new4.txt","wt");
	fwrite(Exit,1,strlen(Exit),pf);
}
