#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
struct std {//���ݽṹ��
	char name[20];
	int num;
	int mark;
};
struct node {//����Ľṹ��
	struct std data;
	struct node* next;
};
struct node* nowheadnnode(void)//�½���ͷ
{
	struct node* headnode = (struct node*)malloc(sizeof(struct node));
	assert(headnode != NULL);
	headnode->next = NULL;
	return headnode;
}
struct node* nownode(struct std data)//�½��ڵ�
{
	struct node*  node= (struct node*)malloc(sizeof(struct node));
	assert(node != NULL);
	node->data = data;
	node->next = NULL;
	return node;
}
void charu(struct node* head, struct std nowdata)//����ڵ�
{
	struct node* node = nownode(nowdata);
	node->next = head->next;
	head->next = node;
}
void prin(struct node* headnode)//�����ӡ
{
	struct node* node = headnode->next;
	printf("����\tѧ��\t�ɼ�\n");
	while(node)
	{
		printf("%s\t%d\t%d\n", node->data.name, node->data.num, node->data.mark);
		node = node->next;
	}
	printf("\n");
}
void shanchu(struct node* head,int num)//ɾ������
{
	struct node* pos = head->next;
	struct node* posf = head;
	if (pos == 'NULL')
	{
		printf("����Ϊ�գ��޷�ɾ��\n");
	}
	else
	{
		while (pos->data.num != num)
		{
			posf->next = pos;
			pos->next = posf->next;
			if (pos=='NULL')
			{
				printf("�����飬�޶�ӦĿ��\n");
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
	system("title �ɼ�ϵͳ"); 
	system("mode con cols=40 lines=20");
	struct node* biao = nowheadnnode();
	struct std po;
	dodo:
	system("cls");
	printf("/*****************/\n");
	printf("/*����У԰�ɼ�ϵͳ*/\n");
	printf("/*  1.¼��ɼ�   */\n");
	printf("/*  2.ɾ���ɼ�   */\n");
	printf("/*  3.��ʾȫ��   */\n");
	printf("/*****************/\n");
	int y;
	scanf_s("%d", &y);
	if (y == 1)
	{
		while (1)
		{
			system("cls");
			classbuf();
			printf("������ѧ������(Ӣ��)���س�ȷ��\n");
			scanf_s("%s", po.name, 20);
			printf("������ѧ��ѧ�ţ��س�ȷ��\n");
			scanf_s("%d", &po.num);
			printf("������ѧ���ɼ����س�ȷ��\n");
			scanf_s("%d", &po.mark);
			charu(biao, po);
			printf("�˳�������0������1����¼�룬�س�ȷ��\n");
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
			printf("��������ɾ����ѧ��ѧ��\n");
			scanf_s("%d",&q);
			printf("�˳�������0������1����ɾ�����س�ȷ��\n");
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
		printf("�˳�������0���س�ȷ��\n");
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