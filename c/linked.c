#include <stdio.h>
#include <malloc.h>   
#include <stdlib.h>   

/**
	����
*/
struct node{
	int data;  
	struct node * pNext;
};


struct node* create_list(void);   
void shuixian(struct node * node);
int main(void){
	
	struct node * pHead = NULL;
	pHead = create_list();
}

void shuixian(struct node * node){
	
	struct node * pNew = node;
	
	struct node * kuai;
	struct node * man;
	
	int count = 0;
	
	while(pNew != NULL){
		count++;
	}
	
	
}


struct node* create_list(void){
	int len;   //�ɹ����ĸ���
	int i;     
	int val;     //Ҫ�洢��ֵ
	
	struct node * pHead = (struct node *)malloc(sizeof(node));
	if(NULL == pHead){
		printf("����ڵ�ʧ��");
		exit(-1);
	}
	
	//pTail ÿ�ζ�ָ�����һ��ָ��
	 struct node * pTail = pHead;
	
	 pTail->pNext = NULL;
	 
	 printf("����������Ҫ���ɵ�����ڵ�ĸ�����len = ");
	 scanf("%d", &len);
	 
	 for(i=0; i<len; i++){
		 printf("�������%���ڵ��ֵ:",i+1);
		 scanf("%d", &val);
		 
		 struct node * p = (struct node *)malloc(sizeof(node));
		 if(NULL == p){
			 printf("����ڵ�ʧ��");
			 exit(-1);
		 }
		 
		 p->data = val;
		 pTail->pNext = p;
		 pTail = p;
		 pTail->pNext = NULL;
	 }

}
