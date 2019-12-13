//prog.c
//#include "func.h" или  void sort(int *x);
//int m[]={8,2,4,1,6,5};
//int N=sizeof(m)/sizeof(int);
//int main() {
// sort(m);
// for(int i=0; i<N; i++) cout<<m[i]<<" ";
// cout<<endl<<N<<endl;
//getch();
//}
//
//func.c
//extern int N;
//void swap(int &x, int &y) {
//     int t=x; x=y; y=t;
//}
//void sort(int *x) {
//  int i, k;
//
//  do {
//      k=0;
//    for(i=1; i<N; i++)
//      if(x[i]<x[i-1]) { swap(x[i], x[i-1]); k=1;}
//  } while(k);
//  cout<<N<<endl;
//}
//
//func.h
//void swap(int &x, int &y);
//void sort(int *x);
//
//
//Передача функции в качестве параметра.
//
//#include <iostream.h>
//int xx (int a) {
//  cout <<a<<"+"<<a<<endl;
//  return a+a;
//}
//int yy ( int a) {
//   cout <<a<<"*"<<a<<endl;
//  return a*a;
//}
//int call (int a, int (*f) (int)) {
//    
//  cout <<"call " << " f() = " << f(a) <<"\n";
//} 
//
//int main () {
// call(3,xx);
// call(4,yy); 
//}
//
//
//Перезагрузка функций
//Используется одно имя, но параметры различны по количеству или типу.
//
//int add(int a,int b) { 
//   return(a + b); 
//}
//int add (int a, int b, int c) {
//   return(a + b + c); 
//}
//int add (int a, float b) {
//   return(b+a); 
//}
//
// main(void) 
//{ 
//   cout <<  add(200, 101) << endl; 
//   cout <<  add(100, 201, 700) << endl; 
//   cout <<  add(700.1,1) << endl; 
//}