#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
struct std {//数据结构体
	char name[20];
	int num;
	int mark;
};
struct node {//链表的结构体
	struct std data;
	struct node* next;
};
struct node* nowheadnnode(void)//新建表头
{
	struct node* headnode = (struct node*)malloc(sizeof(struct node));
	assert(headnode != NULL);
	headnode->next = NULL;
	return headnode;
}
struct node* nownode(struct std data)//新建节点
{
	struct node*  node= (struct node*)malloc(sizeof(struct node));
	assert(node != NULL);
	node->data = data;
	node->next = NULL;
	return node;
}
void charu(struct node* head, struct std nowdata)//插入节点
{
	struct node* node = nownode(nowdata);
	node->next = head->next;
	head->next = node;
}
void prin(struct node* headnode)//历遍打印
{
	struct node* node = headnode->next;
	printf("名字\t学号\t成绩\n");
	while(node)
	{
		printf("%s\t%d\t%d\n", node->data.name, node->data.num, node->data.mark);
		node = node->next;
	}
	printf("\n");
}
void shanchu(struct node* head,int num)//删除函数
{
	struct node* pos = head->next;
	struct node* posf = head;
	if (pos == 'NULL')
	{
		printf("数据为空，无法删除\n");
	}
	else
	{
		while (pos->data.num != num)
		{
			posf->next = pos;
			pos->next = posf->next;
			if (pos=='NULL')
			{
				printf("已历遍，无对应目标\n");
			}
		}
		posf->next = pos->next;
		free(pos);
	}
}
void classbuf(void)
{
	int ch ;
	while (ch = getchar() != '\n' && ch != EOF)
	{
		;
	}
}
int main(void)
{
	system("title 成绩系统"); 
	system("mode con cols=40 lines=20");
	struct node* biao = nowheadnnode();
	struct std po;
	dodo:
	system("cls");
	printf("/*****************/\n");
	printf("/*简易校园成绩系统*/\n");
	printf("/*  1.录入成绩   */\n");
	printf("/*  2.删除成绩   */\n");
	printf("/*  3.显示全部   */\n");
	printf("/*****************/\n");
	int y;
	scanf_s("%d", &y);
	if (y == 1)
	{
		while (1)
		{
			system("cls");
			classbuf();
			printf("请输入学生名字(英文)，回车确定\n");
			scanf_s("%s", po.name, 20);
			printf("请输入学生学号，回车确定\n");
			scanf_s("%d", &po.num);
			printf("请输入学生成绩，回车确定\n");
			scanf_s("%d", &po.mark);
			charu(biao, po);
			printf("退出请输入0，输入1继续录入，回车确定\n");
			classbuf();
			int u;
			scanf_s("%d", &u);
			if (u ==0)
			{
				goto dodo;
			}
		}
	}
	else if (y ==2)
	{
		while (1)
		{
			int q=0;
			system("cls");
			classbuf();
			printf("请输入需删除的学生学号\n");
			scanf_s("%d",&q);
			printf("退出请输入0，输入1继续删除，回车确定\n");
			shanchu(biao,q);
			int t ;
			scanf_s("%d", &t);
			if (t == 0)
			{
				goto dodo;
			}
		}
	}
	else if (y ==3)
	{
		system("cls");
		prin(biao);
		printf("退出请输入0，回车确定\n");
		while (1)
		{
			classbuf();
			int k;
			scanf_s("%d", &k);
			if (k== 0)
			{
				goto dodo;
			}
		}
	}
	else
	{
		classbuf();
		goto dodo;
	}
	return 0;
}