#include <stdio.h>
int main(void)
{
	int a = 1, b = 1,count=1;
	printf("/------�žų˷���-----/\n");
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
	printf("�������λس�����\n");
	getchar();
	return 0;
}