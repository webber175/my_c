#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
struct node {//节点结构体
	int data;
	struct node* prev;//节点的上指针
	struct node* next;//节点的下指针
};
struct nodehead {//链表结构体
	struct node* head;//链表头
	struct node* tail;//链表尾
	size_t size;//长度
};
struct nodehead* initnode(void)//初始化
{
	struct nodehead* node = (struct nodehead*)malloc(sizeof(struct nodehead*));
	assert(node!=NULL);
	node->head = NULL;
	node->tail = NULL;
	node->size = 0;
	return node;
}
struct node* newnode(int data)//新建节点
{
	struct node* node = (struct node*)malloc(sizeof(struct node));
	assert(node != NULL);
	node->data = data;
	node->next = NULL;
	node->prev = NULL;
	return node;
}
void freenode(struct nodehead *list)//释放整个链表
{
	while (list->size)
	{
		struct node *new = list->head;
		list->head = list->head->next;
		free(new);
		new = NULL;
		list->size--;
	}
}
void charu(struct nodehead *list, int data)//头插入函数
{
	struct node *node = newnode(data);
	if (list->size == 0)//长度为0时，该节点既是头，也是尾
	{
		list->head = node;
		list->tail = node;
	}
	else
	{
		/*将新节点的下指针  指向表头所指向的节点*/
		node->next = list->head;
		/*将表头所指的节点里的上指针  指向新节点*/
		/*这是双链表的双指向*/
		list->head->prev = node;
		/*将表头指向新节点*/
		list->head = node;
	}
	list->size++;//长度+1
}
void printfnode(struct nodehead *list)//头历遍
{
	struct node *node = list->head;
	printf("头打印链表数据\n");
	for (int i = 0; i < list->size; i++)
	{
		printf("%d\t", node->data);
		node = node->next;
	}
	printf("\n");
}
void pnode(struct nodehead *list)//尾历遍
{
	struct node *node = list->tail;
	printf("尾打印链表数据\n");
	for (int i = 0; i < list->size; i++)
	{
		printf("%d\t", node->data);
		node = node->prev;
	}
	printf("\n");
}
void classnode(struct nodehead *new, int data)//删除指定数据节点
{
	struct node *node = new->head;
	if (node == NULL)
	{
		printf("链表为空，无法删除\n");
	}
	else
	{
		while (node->data != data)//检测数据
		{
			node = node->next;
		}
		if (node->prev == NULL)//删除表头文件需要改变表头指向
		{
			node->next->prev = NULL;
			new->head = node->next;
		}
		else if (node->next == NULL)//删除表尾文件需要改变表尾指向
		{
			node->prev->next = NULL;
			new->tail = node->prev;
		}
		else//表中无特殊操作
		{
			node->prev->next = node->next;
			node->next->prev = node->prev;
		}
		free(node);
		new->size--;
	}
}
void nodesize(struct nodehead *list)//打印链表长度
{
	printf("现链表长度为%d\n", list->size);
}
int main(void)
{
	struct nodehead *list = initnode();
	charu(list, 3);
	charu(list, 6);
	charu(list, 5);
	charu(list, 9);
	printfnode(list);
	nodesize(list);//打印链表长度
	printf("/------------------/\n");
	classnode(list, 3);
	printfnode(list);
	nodesize(list);
	printf("/------------------/\n");
	pnode(list);
	nodesize(list);
	//freenode(list);
	//nodesize(list);
	//printfnode(list);
	getchar();
	return 0;
}