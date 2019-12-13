#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <string.h>
#include <iostream>
#include <fstream>
#include <clocale>


using namespace std;

main()

{
	setlocale(LC_ALL, "RUS");
    int N,i,j;
  cout << "—колько будет строк?" << endl;
  cin >> N;

  char ch, pr[N][50];
  gets(pr[0]);
  for (i=0;i<N;i++){
    printf("¬ведите строку є %d  \n",i+1);
    gets(pr[i]);
  }


  FILE *pt, *pg, *ps;
  pt=fopen("text.txt","w");

 for (i=0;i<N;i++){
        j=0;
 while (pr[i][j]!='\0'){
  fprintf(pt,"%c",pr[i][j]);
  j++;
     }
 fprintf(pt,"\n");
 }
  fclose(pt);


  string s;
    ifstream fin;
    ofstream fout("rtext.txt");
    fin.open("text.txt");
    if(!fin.is_open()) cout << "file is not found!\n";
    while(!fin.eof()){
        getline(fin,s);
        for(int i(s.length());i>=0;i--)
            fout << s[i];
        fout << endl;
    }
    fin.close();
    fout.close();



                          

  getch();
}
