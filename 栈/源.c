#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
/*
* ջ�������Ϊһ�����飬����ֻ�ܴ�ջ����д����
*/
struct stak {
	int data[10];//ջ������
	int top;//ջ����־
};
void initstak(struct stak** s)//��ʼ��ջ,ͨ����άָ�봫�룬������̬�ڴ棬��return����Ч
{
	*s = (struct stak*)malloc(sizeof(struct stak*));
	assert(*s != NULL);
	(*s)->top = -1;//ջ����־
	/*
	* ջ����־��ջ��Ԫ�ض�Ӧ�������ֵ������ջΪ�յ�ʱ��Ӧ��ջ��ѹ��-1
	*/
}
void instak(struct stak* s, int data)//��ջ
{
	if (s->top == 9)
		printf("stak is full\n");
	else
	{
		s->top++;//ջ������
		s->data[s->top] = data;//�����ݴ���ջ��
	}
}
void outstak(struct stak* s,int* data)//��ջ��ͬ������ָ�봫������
{
	if (s->top == -1)
		printf("��ջ���޷�ȡ��\n");
	else
	{
		*data =s->data[s->top];//����һ��Ҫ*�ţ���Ϊ��Ҫ�������ݵĵ�ַ
		s->top--;
	}
}
void lookstak(struct stak* s, int* data)//��ȡջ����Ϣ
{
	if (s->top == -1)
		printf("��ջ���޷���ȡ\n");
	else
	{
		*data = s->data[s->top];
		printf("��ȡ�ɹ�\n");
	}
}
void prstak(struct stak* s)//��ӡ
{
	for (int i = s->top; i >= 0; i--)
		printf("%d\t", s->data[i]);
	printf("\n");
}
int main(void)
{
	struct stak* s;
	int x=0;
	initstak(&s);
	//��Ҫʹ�� Ѱַ��������ָ�봫�������ݣ���Ϊָ�봫�����ݵ�ԭ����Ǵ�����ַ
	instak(s, 2);
	instak(s, 6);
	instak(s, 8);
	prstak(s);
	outstak(s, &x);
	prstak(s);
	printf("ȡ����������%d\n", x);
	getchar();
	return 0;
}