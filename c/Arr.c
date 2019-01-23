#include <stdio.h>
#include <malloc.h>   //包含malloc函数
#include <stdlib.h>   //包含exit函数

/*
 *实现数组
*/
struct Arr{
	int * pBase; //存储的是数组第一个元素的地址
	int len;    //数据所能容纳的最大的元素的个数
	int cnt;    //当前数组有效元素的个数
};

void init_arr(struct Arr * pArr, int length);   //初始化数组
bool is_empty(struct Arr * pArr);        //该函数是判断数组是否为空
bool is_full(struct Arr * pArr);         ///判断数据是否还可以存储数据
void show_arr(struct Arr * pArr);		//显示数据
bool append_arr(struct Arr * pArr, int val);   //追加数据
bool delete_arr(struct Arr * pArr,int post, int * val); //删除数据
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
	
	//printf("删除后的数据\n");
//	delete_arr(&arr,3,&val);

//	printf("插入数据成功\n");
//	insert_arr(&arr,3,28);
	
	printf("排序过后");
	sort_arr(&arr);

  //	printf("反转过后");
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
			//	printf("进入循环了");
				t = pArr->pBase[i];
				pArr->pBase[i] = pArr->pBase[j];
				pArr->pBase[j] = t;
			}
		}
	}
	
	
}




//初始化数组
void init_arr(struct Arr * pArr, int length)
{
	pArr->pBase = (int *)malloc(sizeof(int) * length); 
    //记住：必须要强转
	//sizeof计算int类型总共有字节数，再乘以你需要的数组的个数，就可以得到一个例如：int [10] = null
	
	//如果pBase等于null 则分配内存失败
	if(NULL == pArr->pBase)
	{
		printf("分配内存失败\n");
		//printf("动态内存分配失败！\n");
		exit(-1);   //终止整个程序
	}
	else
	{
		printf("初始化数组成功\n");
		pArr->len = length;  //pArr最大能容纳是个元素
		pArr->cnt = 0;       //目前没有一个元素
	}
}

//该函数是判断数组是否为空
bool is_empty(struct Arr * pArr)
{
	if(0 == pArr->cnt)
		return true;
	else
		return false;
}

//判断数据是否还可以存储数据
bool is_full(struct Arr * pArr){
	if(pArr->cnt == pArr->len)
		return true;
	else
		return false;
}

//显示数据
void show_arr(struct Arr * pArr)
{
	if(is_empty(pArr)){
		printf("数组为空，没有数据可显示");
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

//追加数据
bool append_arr(struct Arr * pArr, int val)
{
	//判断数组是否满了  如果满了及放回true
	if(is_full(pArr)){
		printf("数组存储语句满了");
		return false;
	}  
	
	//	添加数据
	pArr->pBase[pArr->cnt] = val;
	//pArr有效个数加1
    (pArr->cnt)++;
	//添加成功
	return true;
	
}

//  1 2 3 4 5   post =3 删除数据
bool delete_arr(struct Arr * pArr,int post, int * val)
{	
	//post从那个位置开始删除   需要把要删除的后面的元数往前移动  post是从1开始的
	int i = post;
	
	//判断数组是否为空
	if(is_empty(pArr))
		return false;
	//判断索引值是正确的值
	if(post<1 || post>pArr->cnt)
		return false;
	
	//把要删除的数组存储到val  可以带储区
	*val = pArr->pBase[post-1];
	while(i<pArr->cnt)
	{
		pArr->pBase[i-1] = pArr->pBase[i];
		++i;
	}
	pArr->cnt--;
	return true;
}


//插入数据    1 2 3 4 5
bool insert_arr(struct Arr * pArr, int post, int val)
{
	
	int i;
	if(is_full(pArr)){
		printf("数组已满，插入不了");
		return false;
	}
	
	if(post<1 || post>pArr->cnt+1)
		return false;
	
	//i的初始值为pArr最后一个有效个数， i>=要插入的索引值，(post是从1开始的，需要-1)
	//把要插入数据的索引值后面的数据后移动
	for(i=(pArr->cnt)-1; i>=post-1; --i)
	{
		pArr->pBase[i+1] = pArr->pBase[i];
	}
	pArr->pBase[post-1] = val;
	(pArr->cnt)++;
	
	return true;
}

//反转数组
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




