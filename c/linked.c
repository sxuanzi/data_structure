#include <stdio.h>
#include <malloc.h>   
#include <stdlib.h>   

/**
	链表
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
	int len;   //成功结点的个数
	int i;     
	int val;     //要存储的值
	
	struct node * pHead = (struct node *)malloc(sizeof(node));
	if(NULL == pHead){
		printf("分配节点失败");
		exit(-1);
	}
	
	//pTail 每次都指向最后一个指针
	 struct node * pTail = pHead;
	
	 pTail->pNext = NULL;
	 
	 printf("请输入你需要生成的链表节点的个数：len = ");
	 scanf("%d", &len);
	 
	 for(i=0; i<len; i++){
		 printf("请输入第%个节点的值:",i+1);
		 scanf("%d", &val);
		 
		 struct node * p = (struct node *)malloc(sizeof(node));
		 if(NULL == p){
			 printf("分配节点失败");
			 exit(-1);
		 }
		 
		 p->data = val;
		 pTail->pNext = p;
		 pTail = p;
		 pTail->pNext = NULL;
	 }

}
