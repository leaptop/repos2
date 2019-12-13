
void main(){//English alphabet a b c d e f g h i j k l m n o p q r s t u v w x y z
int a = 10;
int b = &a;//these return the same result 6422156!!
int c = &b;
int d = &c;
printf("%d, %d, %d, %d\n", a, b, c, d);//output: 10, 6422184, 6422180, 6422176
int *e = a;
int *f = e;
int *g = f;
int *h = g;
printf("%d, %d, %d, %d\n", e, f, g, h);//output: 10, 10, 10, 10
//int &i = a;//12	5	C:\AsterAmper01.c	[Error] expected identifier or '(' before '&' token   
//int &i CAN ONLY BE WRITTEN IN PARAMETERS LIST OF A FUNCTION
//int &j = i;//13	5	C:\AsterAmper01.c	[Error] expected identifier or '(' before '&' token
int k = &e;//14	5	C:\AsterAmper01.c	[Error] expected identifier or '(' before '&' token
//int& l = a;//can't do in C, but apparently it's possibble in C++//16	4	C:\AsterAmper01.c	[Error] expected identifier or '(' before '&' token
int *m = &a;//these return the same result 6422156!!
//int &n = *a;// 18	5	C:\AsterAmper01.c	[Error] expected identifier or '(' before '&' token
int *o = *m;
int *p = m;//these return the same result 6422156!!
printf("%d, %d, %d, %d\n", k, m, o, p);// output: 6422144, 6422156, 10, 6422156
int q;
int *r;//r holds the memory address of an integer
q = 3;
r = &q;//r references to q now
*r = 5;// says to alter the memory referenced by r, which is also stored in q
printf("%d\n", q);//output: 5//BTW the reference variable can't be dereferenced(you can't tell it to refer to something else)
//void iswap(int &x, int &y) {}//C++ only//28	16	C:\AsterAmper01.c	[Error] expected ';', ',' or ')' before '&' token
struct student{
	char name[15]; int year;
}student_1, student_2, student_3;//we've declared one structure type, and three objects of the type
//without the 3 names it would be just a structure type(no memory would be allocated)
struct student st[6];//declaring an array of structs
//you can also create a struct, containing pointers to other structs, and thus ... 
//no its better to insert a pointer inside of each struct... or use built in std::list etc in C++
typedef struct rational_fraction{
	int numerator;
	int denominator;
}fraction;//after this declaration we can create the structures using the word fraction, as well as rational_fraction
//a pointer can be created like this: fraction *fr; fr->numerator = 19;
fraction *fr;
fr->numerator = 19;
//std::list<fraction> varList;//C++ only apparently
//struct fraction frr[2];//45	17	C:\AsterAmper01.c	[Error] array type has incomplete element type

}
