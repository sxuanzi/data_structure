package com.array;

/**
 * 数组的插入、删除、按照下标随机访问操作
 * @author xuan
 *
 */
public class Array {
	//定义整型数据打他保存数据
	public int data[];
	//定义数组的长度
	private int n;
	//定义数组保存的个数
	private int count;
	
	//构造方法，定义数组大小
	public Array(int capacity) {
		this.data = new int[capacity];
		this.n = capacity;
		this.count = 0;
	}
	
	//根据索引值找到元素进行返回
	/**
	 * 根据索引值来查找数据
	 * 第一：我们可以知道传进来的是一个数字，
	 * 第二：查找的数据要进行返回，查找的内容是整形，返回的是整型
	 * 第三：我们需要考虑传入的值，小于或者大于就找不到索引值了
	 * @param index
	 * @return
	 */
	public int find(int index){
		if(index<0 || index>=count) return -1;
		return data[index];		
	}
	
	//判断元素是否满了   如果元素满，则返回false;
	public boolean full(){
		boolean flg = true;
		if(count == n)
			flg = false;
		return flg;
	}
	
	/**
	 * 添加元素
	 * @param value
	 * @return
	 */
	public boolean add(int value){
		if(!full())
			return false;
		
		data[count++] = value;
		return true;
	}
	
	//插入元素
	public boolean insert(int index, int value){
		//数组空间已经满了
		if(count == n){
			System.out.print("位置已经满了，没用可插入的元素了");
			return false;
		}
		
		//1 2 3 4    2   1
		if(index <0 || index>count){
			System.out.println("插入的元素不合法");
			return false;
		}
		
		/**
		 * 因为数组的下标是从0开始的，
		 */
		for(int i = count; i>index-1; i--){
			data[i] = data[i-1];
		}
		
		data[index-1] = value;
		++count;
		
		return true;
		
	}
	
	/**
	 * 输出所有的元素
	 */
	public void printAll(){
		for(int i=0; i<count; ++i){
			System.out.print(data[i]+" ");
		}
		System.out.println();
	
	}
	
	/**
	 * 删除元素
	 * @param args
	 */
	public boolean delete(int index){
		if(index<0 || index>=count ){
			System.out.print("你输入的值不合理");
			return false;
		}
		
		// 1 2 3 4
		for(int i=index-1; i<=count; i++){
			data[i] = data[i+1];
		}
		--count;
		return true;
	}
	
	
	
}
