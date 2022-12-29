#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
/*
* 栈可以理解为一个数组，但是只能从栈顶读写数据
*/
struct stak {
	int data[10];//栈的容量
	int top;//栈顶标志
};
void initstak(struct stak** s)//初始化栈,通过二维指针传入，传出动态内存，比return更高效
{
	*s = (struct stak*)malloc(sizeof(struct stak*));
	assert(*s != NULL);
	(*s)->top = -1;//栈顶标志
	/*
	* 栈顶标志的栈顶元素对应着数组的值，所以栈为空的时候应将栈顶压至-1
	*/
}
void instak(struct stak* s, int data)//入栈
{
	if (s->top == 9)
		printf("stak is full\n");
	else
	{
		s->top++;//栈顶弹起
		s->data[s->top] = data;//将数据存入栈顶
	}
}
void outstak(struct stak* s,int* data)//出栈，同理利用指针传出数据
{
	if (s->top == -1)
		printf("空栈，无法取出\n");
	else
	{
		*data =s->data[s->top];//这里一定要*号，因为需要传出数据的地址
		s->top--;
	}
}
void lookstak(struct stak* s, int* data)//读取栈顶信息
{
	if (s->top == -1)
		printf("空栈，无法读取\n");
	else
	{
		*data = s->data[s->top];
		printf("读取成功\n");
	}
}
void prstak(struct stak* s)//打印
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
	//需要使用 寻址符来接收指针传出的数据，因为指针传出数据的原理就是传出地址
	instak(s, 2);
	instak(s, 6);
	instak(s, 8);
	prstak(s);
	outstak(s, &x);
	prstak(s);
	printf("取出的数据是%d\n", x);
	getchar();
	return 0;
}