#include <stdio.h>
#include <malloc.h>

typedef struct queue{
	int * pBase;  //�������ĵ�һ����ַ
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
	//����6��int����
	pQ->pBase = (int *)malloc(sizeof(int) * 6);
	
	pQ->front = 0;
	pQ->rear = 0;	
}

//�ж������Ƿ��Ѿ�����,���rear+1����front�ʹ�����������rear+1����������ͬʱ����������������һ��Ԫ�ز��ᱻʹ��
bool full_queue(QUEUE * pQ){
	if((pQ->rear + 1)%6 == pQ->front)
		return true;
	else
		return false;
}
//���
bool en_queue(QUEUE * pQ,int val){
	//�ж��Ƿ���
	if(full_queue(pQ)){
		return false;
	}else{
		//�Ƚ����ݷŶ�rear��λ��
		pQ->pBase[pQ->rear] = val;
		//Ȼ��rear+1
		pQ->rear = (pQ->rear+1)%6;
		return true;
	}
}

void traverse_queue(QUEUE * pQ){
	//�Ӷ�ͷ��ʼ���������ܸı�front��ֵ�������Ӿ͸ı��������ֵ
	//���Ծͽ�front��ֵ��ֵ��i����i������
	int i = pQ->front;
	//���i==rear(��β)���ʾ����Ϊ�գ����˳�����ѭ��
	while(i!=pQ->rear){
		//����������������ǵý�i+1,ʹ��i����ָ����һ��Ԫ��
		printf("%d", pQ->pBase[i]);
		i = (i+1)%6;
	}
	printf("\n");
	return ;
}

//�÷������������ж������Ƿ�Ϊ�գ����front=rear������Ϊ��
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
		//�Ƚ����ӵ�Ԫ����������
		*pVal = pQ->pBase[pQ->front];
		//Ȼ��front��ֵ+1   ���ʾ����Ԫ�ص�ֵ�����ˣ���Ϊ�����ǴӶ�ͷ���еģ����Ծͽ���ͷ+1
		pQ->front = (pQ->front+1)%6;
		return true;
	}
	
}

