#include <stdio.h>
#include <stdlib.h>
//#define str struct;
struct Node {//�ṹ��1
	int data;//������
	struct Node* next;//����һ��ָ�������ָ�룬Ϊ�����ָ����
};
struct Node* headhead(void)//����һ����ͷ����������ֵΪ�ṹ��ָ��
{
	/*��Node�����nodehead����Ϊ��ͷ*/
	struct Node* nodeHead = (struct Node*)malloc(sizeof(struct Node));//���������ǽṹ��1���ڴ��С
	//�ڸ����ڴ��nodehead�ӽṹ��ָ�����˽ṹ�����
	nodeHead->next = NULL;//����ֵ
	return nodeHead;
}
struct Node* ddnode(int data)//�½��ڵ㺯��
{
	struct Node* nowData = (struct Node*)malloc(sizeof(struct Node));
	nowData->data = data;
	nowData->next = NULL;
	return nowData;
}
void printflin(struct Node* head)//��ӡ��������ָ����ͷ�ĵ�������������ӡ
{
	struct Node* pmove = head->next;//��ͷ�������ݣ����Դӵڶ�����ʼ
	while(pmove)//��ӡ�Ľڵ�ָ�벻��Ϊ��
	{
		printf("%d\t", pmove->data);//��ӡ
		pmove=pmove->next;//ת����һ��
	}
	printf("\n");
}
void charu(struct Node* head, int data)//���뺯�������ηֱ���:Ҫ����ı�ͷ������ڵ�������
{
	struct Node* newdata = ddnode(data);//�½��ڵ�
	newdata->next = head->next;//��ָ��Ͽ����ýڵ����
	head->next = newdata;
}
void shanchu(struct Node* headnode,int data)//ɾ������������Ϊ����ɾ���ڵ�ı�ͷ���ýڵ��������
{
	struct Node* posnode = headnode->next;//posnodeΪ��Ҫɾ���Ľڵ�
	struct Node* posnodef = headnode;//posnodefΪɾ���ڵ����һ���ڵ㣬��Ҫ��ɾ�����������
	if (posnode == NULL)
	{
		printf("ɾ��ʧ�ܣ�����ΪNULL\n");
	}
	else
	{
		while (posnode->data!=data)
		{
			posnodef = posnode;//����posnode��posnodef��˳�򣬼�����
			posnode = posnode->next;
			if (posnode == NULL)
			{
				printf("����β��δ�ҵ�");
				break;
			}
		}
		posnodef->next = posnode->next;//�ҵ��󣬽�posnodefָ��posnode����һ���ڵ㣬��������
		free(posnode);//ʹ��free�����ͷ��ڴ�
	}
}
int main()
{
	struct Node* zhen = headhead();//������ͷΪzhen
	charu(zhen, 5);//�����ͷ
	charu(zhen, 9);
	charu(zhen, 7);
	printflin(zhen);//��ӡ����
	shanchu(zhen,7);//ɾ���ڵ�
	printflin(zhen);
	system("pause");
	return 0;
}
