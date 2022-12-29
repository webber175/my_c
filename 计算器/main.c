#include <stdio.h>
int main(void)
{
	int  a, b;
	char c;
	printf("/----简易计算器----/\n");
	printf("输入后请回车确定\n");
	printf("请输入第一个数\n");
	scanf_s("%d",&a);
	printf("请输入运算符\n");
	scanf_s("%s", &c,10);
	printf("请输入第二个数\n");
	scanf_s("%d", &b);
	if (c == '+')
	{
		printf("%d+%d=%d", a, b, a + b);
	}
	else if (c == '*')
	{
		printf("%d*%d=%d", a, b, a * b);
	}
	else if (c == '*')
	{
		printf("%d-%d=%d", a, b, a - b);
	}
	else if (c == '*')
	{
		printf("%d/%d=%d", a, b, a / b);
	}
	getchar();
	return 0;
}