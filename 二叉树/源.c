#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <Windows.h>
struct tree {//���Ľṹ
	int data;
	struct tree* ld;
	struct tree* rd;
};
struct stak {//ջ�Ľṹ��
	int data[10];
	int top;
};
void headtree(struct tree** tree,int data)//����
{
	*tree = (struct tree*)malloc(sizeof(struct tree));
	assert(*tree != NULL);
	(*tree)->data = data;
	(*tree)->ld = NULL;
	(*tree)->rd = NULL;
}
void newtree(struct tree* tree, int data)
{
	
}
//void initstak(s)
int main(void)
{
	struct tree* tree;
	headtree(&tree,1);
	getchar();
	return 0;
}
/*
* δ��ɣ���ѧ�����Խṹ���ٲ�
*/