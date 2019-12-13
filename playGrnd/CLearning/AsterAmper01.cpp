void main(){//English alphabet a b c d e f g h i j k l m n o p q r s t u v w x y z
int a = 10;
int b = &a;
int c = &b;
int d = &c;
printf("%d, %d, %d, %d\n", a, b, c, d);//output: 10, 6422184, 6422180, 6422176
int *e = a;
int *f = e;
int *g = f;
int *h = g;
printf("%d, %d, %d, %d\n", e, f, g, h);//output: 10, 10, 10, 10
//int &i = a;//12	5	C:\Users\Stepan\source\repos\CLearning\AsterAmper01.c	[Error] expected identifier or '(' before '&' token   
//int &i CAN ONLY BE WRITTEN IN PARAMETERS LIST OF A FUNCTION
//int &j = i;//13	5	C:\Users\Stepan\source\repos\CLearning\AsterAmper01.c	[Error] expected identifier or '(' before '&' token
int k = &e;//14	5	C:\Users\Stepan\source\repos\CLearning\AsterAmper01.c	[Error] expected identifier or '(' before '&' token
int& l = a;//can't do in C//compilation error in C
int &m = &a;
int &n = *a;
printf("%d, %d, %d, %d\n", k, l, m, n);
}
