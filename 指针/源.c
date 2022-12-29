#include<stdio.h>
int add(int x)
{
	return x + 5;
}
void asd(int* x)
{
	*x =*x+5;
}
int main(void)
{
	int x = 4;
	printf("%d\n",add(5));
	asd(&x);
	printf("%d\n",x);
	return 0;
}