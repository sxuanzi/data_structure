#include <stdio.h>
#include <malloc.h>   //����malloc����
#include <stdlib.h>   //����exit����

/*
 *ʵ������
*/
struct Arr{
	int * pBase; //�洢���������һ��Ԫ�صĵ�ַ
	int len;    //�����������ɵ�����Ԫ�صĸ���
	int cnt;    //��ǰ������ЧԪ�صĸ���
};

void init_arr(struct Arr * pArr, int length);   //��ʼ������
bool is_empty(struct Arr * pArr);        //�ú������ж������Ƿ�Ϊ��
bool is_full(struct Arr * pArr);         ///�ж������Ƿ񻹿��Դ洢����
void show_arr(struct Arr * pArr);		//��ʾ����
bool append_arr(struct Arr * pArr, int val);   //׷������
bool delete_arr(struct Arr * pArr,int post, int * val); //ɾ������
bool insert_arr(struct Arr * pArr, int post, int val);
void sort_arr(struct Arr * pArr);
void inversion_arr(struct Arr * pArr);


int main(void){
	
	struct Arr arr; //
	int val;
	
	init_arr(&arr,10);
	
	append_arr(&arr,2);
	append_arr(&arr,5);
	append_arr(&arr,6);
	append_arr(&arr,0);
	append_arr(&arr,10);
	
	show_arr(&arr);
	
	//printf("ɾ���������\n");
//	delete_arr(&arr,3,&val);

//	printf("�������ݳɹ�\n");
//	insert_arr(&arr,3,28);
	
	printf("�������");
	sort_arr(&arr);

  //	printf("��ת����");
  //	inversion_arr(&arr);

	show_arr(&arr);
	
	return 0;
	
}

// 1 2 3 4 5
void sort_arr(struct Arr * pArr)
{
	int i, j, t;
	
	for(i=0; i<pArr->cnt; ++i)
	{
		for(j=i+1; j<pArr->cnt;++j)
		{
			if(pArr->pBase[i] < pArr->pBase[j])
			{
			//	printf("����ѭ����");
				t = pArr->pBase[i];
				pArr->pBase[i] = pArr->pBase[j];
				pArr->pBase[j] = t;
			}
		}
	}
	
	
}




//��ʼ������
void init_arr(struct Arr * pArr, int length)
{
	pArr->pBase = (int *)malloc(sizeof(int) * length); 
    //��ס������Ҫǿת
	//sizeof����int�����ܹ����ֽ������ٳ�������Ҫ������ĸ������Ϳ��Եõ�һ�����磺int [10] = null
	
	//���pBase����null ������ڴ�ʧ��
	if(NULL == pArr->pBase)
	{
		printf("�����ڴ�ʧ��\n");
		//printf("��̬�ڴ����ʧ�ܣ�\n");
		exit(-1);   //��ֹ��������
	}
	else
	{
		printf("��ʼ������ɹ�\n");
		pArr->len = length;  //pArr����������Ǹ�Ԫ��
		pArr->cnt = 0;       //Ŀǰû��һ��Ԫ��
	}
}

//�ú������ж������Ƿ�Ϊ��
bool is_empty(struct Arr * pArr)
{
	if(0 == pArr->cnt)
		return true;
	else
		return false;
}

//�ж������Ƿ񻹿��Դ洢����
bool is_full(struct Arr * pArr){
	if(pArr->cnt == pArr->len)
		return true;
	else
		return false;
}

//��ʾ����
void show_arr(struct Arr * pArr)
{
	if(is_empty(pArr)){
		printf("����Ϊ�գ�û�����ݿ���ʾ");
	}
	else
	{
		int i;
		for(i=0; i<pArr->cnt; ++i)
		{
			printf("%d ", pArr->pBase[i]);
			printf("\n");
		}
	}
}

//׷������
bool append_arr(struct Arr * pArr, int val)
{
	//�ж������Ƿ�����  ������˼��Ż�true
	if(is_full(pArr)){
		printf("����洢�������");
		return false;
	}  
	
	//	�������
	pArr->pBase[pArr->cnt] = val;
	//pArr��Ч������1
    (pArr->cnt)++;
	//��ӳɹ�
	return true;
	
}

//  1 2 3 4 5   post =3 ɾ������
bool delete_arr(struct Arr * pArr,int post, int * val)
{	
	//post���Ǹ�λ�ÿ�ʼɾ��   ��Ҫ��Ҫɾ���ĺ����Ԫ����ǰ�ƶ�  post�Ǵ�1��ʼ��
	int i = post;
	
	//�ж������Ƿ�Ϊ��
	if(is_empty(pArr))
		return false;
	//�ж�����ֵ����ȷ��ֵ
	if(post<1 || post>pArr->cnt)
		return false;
	
	//��Ҫɾ��������洢��val  ���Դ�����
	*val = pArr->pBase[post-1];
	while(i<pArr->cnt)
	{
		pArr->pBase[i-1] = pArr->pBase[i];
		++i;
	}
	pArr->cnt--;
	return true;
}


//��������    1 2 3 4 5
bool insert_arr(struct Arr * pArr, int post, int val)
{
	
	int i;
	if(is_full(pArr)){
		printf("�������������벻��");
		return false;
	}
	
	if(post<1 || post>pArr->cnt+1)
		return false;
	
	//i�ĳ�ʼֵΪpArr���һ����Ч������ i>=Ҫ���������ֵ��(post�Ǵ�1��ʼ�ģ���Ҫ-1)
	//��Ҫ�������ݵ�����ֵ��������ݺ��ƶ�
	for(i=(pArr->cnt)-1; i>=post-1; --i)
	{
		pArr->pBase[i+1] = pArr->pBase[i];
	}
	pArr->pBase[post-1] = val;
	(pArr->cnt)++;
	
	return true;
}

//��ת����
void inversion_arr(struct Arr * pArr)
{
	int i,t;
	int j = pArr->cnt-1;
	while(i < j)
	{
		t = pArr->pBase[i];
		pArr->pBase[i] = pArr->pBase[j];
		pArr->pBase[j] = t;
		i++;
		j--;
	}
	return;
}




