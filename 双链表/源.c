#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
struct node {//�ڵ�ṹ��
	int data;
	struct node* prev;//�ڵ����ָ��
	struct node* next;//�ڵ����ָ��
};
struct nodehead {//����ṹ��
	struct node* head;//����ͷ
	struct node* tail;//����β
	size_t size;//����
};
struct nodehead* initnode(void)//��ʼ��
{
	struct nodehead* node = (struct nodehead*)malloc(sizeof(struct nodehead*));
	assert(node!=NULL);
	node->head = NULL;
	node->tail = NULL;
	node->size = 0;
	return node;
}
struct node* newnode(int data)//�½��ڵ�
{
	struct node* node = (struct node*)malloc(sizeof(struct node));
	assert(node != NULL);
	node->data = data;
	node->next = NULL;
	node->prev = NULL;
	return node;
}
void freenode(struct nodehead *list)//�ͷ���������
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
void charu(struct nodehead *list, int data)//ͷ���뺯��
{
	struct node *node = newnode(data);
	if (list->size == 0)//����Ϊ0ʱ���ýڵ����ͷ��Ҳ��β
	{
		list->head = node;
		list->tail = node;
	}
	else
	{
		/*���½ڵ����ָ��  ָ���ͷ��ָ��Ľڵ�*/
		node->next = list->head;
		/*����ͷ��ָ�Ľڵ������ָ��  ָ���½ڵ�*/
		/*����˫�����˫ָ��*/
		list->head->prev = node;
		/*����ͷָ���½ڵ�*/
		list->head = node;
	}
	list->size++;//����+1
}
void printfnode(struct nodehead *list)//ͷ����
{
	struct node *node = list->head;
	printf("ͷ��ӡ��������\n");
	for (int i = 0; i < list->size; i++)
	{
		printf("%d\t", node->data);
		node = node->next;
	}
	printf("\n");
}
void pnode(struct nodehead *list)//β����
{
	struct node *node = list->tail;
	printf("β��ӡ��������\n");
	for (int i = 0; i < list->size; i++)
	{
		printf("%d\t", node->data);
		node = node->prev;
	}
	printf("\n");
}
void classnode(struct nodehead *new, int data)//ɾ��ָ�����ݽڵ�
{
	struct node *node = new->head;
	if (node == NULL)
	{
		printf("����Ϊ�գ��޷�ɾ��\n");
	}
	else
	{
		while (node->data != data)//�������
		{
			node = node->next;
		}
		if (node->prev == NULL)//ɾ����ͷ�ļ���Ҫ�ı��ͷָ��
		{
			node->next->prev = NULL;
			new->head = node->next;
		}
		else if (node->next == NULL)//ɾ����β�ļ���Ҫ�ı��βָ��
		{
			node->prev->next = NULL;
			new->tail = node->prev;
		}
		else//�������������
		{
			node->prev->next = node->next;
			node->next->prev = node->prev;
		}
		free(node);
		new->size--;
	}
}
void nodesize(struct nodehead *list)//��ӡ������
{
	printf("��������Ϊ%d\n", list->size);
}
int main(void)
{
	struct nodehead *list = initnode();
	charu(list, 3);
	charu(list, 6);
	charu(list, 5);
	charu(list, 9);
	printfnode(list);
	nodesize(list);//��ӡ������
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