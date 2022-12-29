#include <stdio.h>
#include <stdlib.h>
//#define str struct;
struct Node {//结构体1
	int data;//数据域
	struct Node* next;//定义一个指向自身的指针，为链表的指针域
};
struct Node* headhead(void)//定义一个表头函数，返回值为结构体指针
{
	/*将Node定义给nodehead，意为表头*/
	struct Node* nodeHead = (struct Node*)malloc(sizeof(struct Node));//这里分配的是结构体1的内存大小
	//在给予内存后nodehead从结构体指针变成了结构体变量
	nodeHead->next = NULL;//赋初值
	return nodeHead;
}
struct Node* ddnode(int data)//新建节点函数
{
	struct Node* nowData = (struct Node*)malloc(sizeof(struct Node));
	nowData->data = data;
	nowData->next = NULL;
	return nowData;
}
void printflin(struct Node* head)//打印函数，对指定表头的单链表进行历遍打印
{
	struct Node* pmove = head->next;//表头不存数据，所以从第二个开始
	while(pmove)//打印的节点指针不能为空
	{
		printf("%d\t", pmove->data);//打印
		pmove=pmove->next;//转到下一个
	}
	printf("\n");
}
void charu(struct Node* head, int data)//插入函数，传参分别是:要插入的表头，插入节点存的数据
{
	struct Node* newdata = ddnode(data);//新建节点
	newdata->next = head->next;//将指针断开，让节点插入
	head->next = newdata;
}
void shanchu(struct Node* headnode,int data)//删除函数，传参为：想删除节点的表头，该节点里的数据
{
	struct Node* posnode = headnode->next;//posnode为需要删除的节点
	struct Node* posnodef = headnode;//posnodef为删除节点的上一个节点，需要在删除后接上链表
	if (posnode == NULL)
	{
		printf("删除失败，链表为NULL\n");
	}
	else
	{
		while (posnode->data!=data)
		{
			posnodef = posnode;//保持posnode和posnodef的顺序，继续找
			posnode = posnode->next;
			if (posnode == NULL)
			{
				printf("到表尾，未找到");
				break;
			}
		}
		posnodef->next = posnode->next;//找到后，将posnodef指向posnode的下一个节点，接上链表
		free(posnode);//使用free（）释放内存
	}
}
int main()
{
	struct Node* zhen = headhead();//创建表头为zhen
	charu(zhen, 5);//插入表头
	charu(zhen, 9);
	charu(zhen, 7);
	printflin(zhen);//打印历遍
	shanchu(zhen,7);//删除节点
	printflin(zhen);
	system("pause");
	return 0;
}
