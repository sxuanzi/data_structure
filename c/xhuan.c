#include <stdio.h>
#include <malloc.h>

typedef struct queue{
	int * pBase;  //存放数组的第一个地址
	int front;
	int rear;
	
}QUEUE;

void init(QUEUE * pQ);
bool en_queue(QUEUE * pQ, int val);
void traverse_queue(QUEUE * pQ);
bool full_queue(QUEUE * pQ);
bool out_queue(QUEUE * pQ, int * pVal);
bool emput_queue(QUEUE * pQ);


int main(void){
	int val;
	QUEUE Q;
	init(&Q);
	en_queue(&Q,1);
	en_queue(&Q,2);
	en_queue(&Q,3);
	en_queue(&Q,4);
	en_queue(&Q,5);
	en_queue(&Q,6);
	en_queue(&Q,7);
	traverse_queue(&Q);
	out_queue(&Q,&val);
	traverse_queue(&Q);

	return 0;
}

void init(QUEUE * pQ){
	//分配6个int类型
	pQ->pBase = (int *)malloc(sizeof(int) * 6);
	
	pQ->front = 0;
	pQ->rear = 0;	
}

//判断数组是否已经满了,如果rear+1等于front就代表数组满（rear+1）数组满的同时，导致了数组的最后一个元素不会被使用
bool full_queue(QUEUE * pQ){
	if((pQ->rear + 1)%6 == pQ->front)
		return true;
	else
		return false;
}
//入队
bool en_queue(QUEUE * pQ,int val){
	//判断是否满
	if(full_queue(pQ)){
		return false;
	}else{
		//先将数据放都rear的位置
		pQ->pBase[pQ->rear] = val;
		//然后将rear+1
		pQ->rear = (pQ->rear+1)%6;
		return true;
	}
}

void traverse_queue(QUEUE * pQ){
	//从队头开始遍历，不能改变front的值，这样子就改变了数组的值
	//所以就将front的值赋值给i，将i来控制
	int i = pQ->front;
	//如果i==rear(队尾)则表示数组为空，就退出遍历循环
	while(i!=pQ->rear){
		//将数组输出出来，记得将i+1,使得i可以指向下一个元素
		printf("%d", pQ->pBase[i]);
		i = (i+1)%6;
	}
	printf("\n");
	return ;
}

//该方法的作用是判断数组是否为空，如果front=rear则数组为空
bool emput_queue(QUEUE * pQ){
	if(pQ->front == pQ->rear)
		return true;
	else
		return false;
}

bool out_queue(QUEUE * pQ, int * pVal){
	
	if(emput_queue(pQ)){
		return false;
	}else{
		//先将出队的元数保存起来
		*pVal = pQ->pBase[pQ->front];
		//然后将front的值+1   则表示将该元素的值出队了，因为出队是从队头进行的，所以就将队头+1
		pQ->front = (pQ->front+1)%6;
		return true;
	}
	
}

