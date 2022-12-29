#include <stdio.h>
int main(void)
{
	int a = 1, b = 1,count=1;
	printf("/------九九乘法表-----/\n");
	for (a = 1; a < 10; a++)
	{
		printf("%d*1=%2d", a, a );
		if (a > 1)
		{
			count++;
			for (b = 2;b<=count;b++)
			{
				printf("  ");
				printf("%d*%d=%2d", a, b, a * b);
			}
		}
		printf("\n");
	}
	printf("/********************/\n");
	printf("按下两次回车结束\n");
	getchar();
	return 0;
}