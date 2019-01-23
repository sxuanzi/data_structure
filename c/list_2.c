#include <stdio.h>
#include <malloc.h>
#include <stdlib.h>

struct node{
	int data;//�洢������
	struct node * pNext; //�洢ָ����
}NODE;   //node �ȼ���struct Node   *PNODE �ȼ���struct * node


struct node * create_list(void);
void traverser_list(struct node * pHead);
int main(void){
	
	struct node * pHead = NULL;
	pHead = create_list();
	traverser_list(pHead);
	
	return 0;
}

struct node* create_list(void){
	int len;   //���������Ч�ڵ����
	int i;
	int val;   //������ʱ����û�����Ľڵ��ֵ
	
	//����һ���ڵ㣬Ȼ��ѽڵ�ĵ�ַ���͸�pHead
	struct node*  pHead = (struct node *)malloc(sizeof(NODE));//pHeadͷ�ڵ�
	if(NULL ==pHead){
		printf("����ڵ�ʧ��");
		exit(-1);
	}
	
	//����һ��ָ����ʹ�����ָ����ÿ�ζ�ָ�����һ���ڵ㣬��Ϊ��δ��һ���ڵ㣬pTailָ��phead
	struct node * pTail = pHead;    //pTailָ��ͷ�ڵ�
	pTail->pNext = NULL;//��Ϊ��û�з���ڵ㣬����ͷ�ڵ��ָ����ָ���
	
	printf("����������Ҫ�����ɵ�����ڵ�ĸ���:len = ");
	scanf("%d",&len);
	
	for(i=0;i<len;i++){
		printf("�������%d���ڵ��ֵ��",i+1);
		scanf("%d",&val);
		
		//ÿѭ��һ�ξʹ���һ���ڵ㣬Ȼ����pָ��ýڵ�
		struct node * p = (struct node *)malloc(sizeof(NODE));
		if(NULL ==p){
		printf("����ڵ�ʧ��");
		exit(-1);
	    }
		
		//�����ݷŵ�p�ڵ��������
		p->data = val;
		//��p�ҵ�pTail(��ΪpTailָ��pHead�����Ծ��ǰ�p����pHead)��
		pTail->pNext = p;
		//��
		pTail = p;
		pTail->pNext = NULL;
		
	}
	
	return pHead;
}

void traverser_list(struct node * pHead){
	struct node * pNew = pHead->pNext;  

	while(pNew!=NULL){	
		int val = pNew->data;
		printf("%d",val);
		pNew = pNew->pNext;
	}
}





