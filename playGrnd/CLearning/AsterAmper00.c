void swap(int *x, int *y)//works in C
{
	int temp = *x;
	*x = *y;
	*y = temp;
}
//void iswap(int &x, int &y){}//

void main(){
	int a[] = {0,4};
	swap(&a[0], &a[1]);
	for(int i = 0; i < 2; i++){			
		printf("%d, ", a[i]);			
	}//output: 4, 0,
	iswap(a[0], a[1]);
		for(int i = 0; i < 2; i++){			
		printf("%d, ", a[i]);			
	}
}
