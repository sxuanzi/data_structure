#include <stdio.h>
#include <malloc.h>
#include <stdlib.h>

struct node{
	int data;//存储数据域
	struct node * pNext; //存储指针域
}NODE;   //node 等价于struct Node   *PNODE 等价于struct * node


struct node * create_list(void);
void traverser_list(struct node * pHead);
int main(void){
	
	struct node * pHead = NULL;
	pHead = create_list();
	traverser_list(pHead);
	
	return 0;
}

struct node* create_list(void){
	int len;   //用来存放有效节点个数
	int i;
	int val;   //用来临时存放用户输入的节点的值
	
	//创建一个节点，然后把节点的地址发送给pHead
	struct node*  pHead = (struct node *)malloc(sizeof(NODE));//pHead头节点
	if(NULL ==pHead){
		printf("分配节点失败");
		exit(-1);
	}
	
	//创建一个指针域，使得这个指针域每次都指向最后一个节点，因为还未有一个节点，pTail指向phead
	struct node * pTail = pHead;    //pTail指向头节点
	pTail->pNext = NULL;//因为还没有分配节点，所有头节点的指针域指向空
	
	printf("请输入您需要的生成的链表节点的个数:len = ");
	scanf("%d",&len);
	
	for(i=0;i<len;i++){
		printf("请输入第%d个节点的值：",i+1);
		scanf("%d",&val);
		
		//每循环一次就创建一个节点，然后让p指向该节点
		struct node * p = (struct node *)malloc(sizeof(NODE));
		if(NULL ==p){
		printf("分配节点失败");
		exit(-1);
	    }
		
		//将数据放到p节点的数据域
		p->data = val;
		//把p挂到pTail(因为pTail指向pHead，所以就是把p挂上pHead)上
		pTail->pNext = p;
		//让
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





