#include <stdio.h>
int main(void)
{
	int  a, b;
	char c;
	printf("/----���׼�����----/\n");
	printf("�������س�ȷ��\n");
	printf("�������һ����\n");
	scanf_s("%d",&a);
	printf("�����������\n");
	scanf_s("%s", &c,10);
	printf("������ڶ�����\n");
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