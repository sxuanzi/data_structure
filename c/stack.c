# include <stdio.h>
# include <malloc.h>
# include <stdlib.h>
typedef struct Node{
	int data;
	struct Node * pNext;
}NODE;

typedef struct Stack{
	struct Node * pTop;
	struct Node * pBottom;
}STACK;

void init(struct Stack * stack);
void push(struct Stack * stack,int val);
void traverse(struct Stack * stack);
bool empty(struct Stack * stack);
bool pop(struct Stack * stack, int * val);
void clear(struct Stack * stack);

int main(void){
	STACK S;
	int val;
	init(&S);
	push(&S, 1);
	push(&S, 3);
	push(&S, 4);
	push(&S, 5);
	traverse(&S);
	if(pop(&S,&val)){
		printf("成功");
		traverse(&S);
	}else{
		printf("失败");
	}
	clear(&S);
	printf("清空成功");
	traverse(&S);
	if(pop(&S,&val)){
		printf("成功");
		traverse(&S);
	}else{
		printf("失败");
	}
	
	
	
	
}

void init(struct Stack * stack){
	
	stack->pBottom = (struct Node *)malloc(sizeof(NODE));
	if(NULL == stack->pBottom){
		printf("分配内存失败");
		exit(-1);
	}else{
		stack->pTop = stack->pBottom;
		stack->pTop->pNext =NULL;
	}
	
	
	
}

void push(struct Stack * stack,int val){
	
	struct Node * pNew = (struct Node *)malloc(sizeof(NODE));
	pNew->data = val;
	pNew->pNext = stack->pTop;
	stack->pTop = pNew;
	
	return;
	
}

void traverse(struct Stack * stack){
	struct Node * p = stack->pTop;
	
	while( p!=stack->pBottom ){
		printf("%d",p->data);
		p = p->pNext;
	}
	
}

bool empty(struct Stack * stack){
	if(stack->pTop == stack->pBottom){
		return true;
	}else{
		return false;
	}
}

bool pop(struct Stack * stack, int * val){
	struct Node * p = stack->pTop;
	
	if(empty(stack)){
		printf("出栈失败");
		return false;
	}else{
		* val = p->data;
		stack->pTop = p->pNext;
		free(p);
		p = NULL;
	}
	
	
	
	return true;
	
}

void clear(struct Stack * stack){
	
	if(empty(stack)){
		return;
	}else{
		struct Node * p = stack->pTop;
		struct Node * q;
		while(p!=stack->pBottom){
			q= p->pNext;
			free(p);
			p = q;
		}
		stack->pTop = stack->pBottom;
	}
	
}

