package com.array;

public class GenericArray<T> {
	
	private T[] data;
	private int size;

	public GenericArray(int capacity) {
		data = (T[]) new Object[capacity];
	}
	
	public GenericArray() {
		this(10);
	}
	
	/**
	 * 获取数组的容量
	 * @return
	 */
	public int getCapacity(){
		return data.length;
	}
	
	/**
	 * 获取当前元素的个数
	 * @return
	 */
	public int count(){
		return size;
	}
	
	/**
	 * 当前元素是否为空
	 * @return
	 */
	public boolean isEmpty(){
		return size ==0;
	}
	
	//修改index位置的元素
	public void set(int index,T e){
		checkIndex(index);
		data[index] = e;
	}
	
	//获取对应index位置的元素
	public T get(int index){
		checkIndex(index);
		return data[index];
	}
	
	//查看数组是否包含元素
	public boolean contains(T s){
		for (int i = 1; i <= size; i++) {
			if(s.equals(data[i])){
				return true;
			}
		}
		return false;
	}
	
	//获取对应元素的下标，未找到，返回-1
	public int find(T e){
		for(int i = 1; i<=size; i++){
			if(data[i].equals(e)){
				return i;
			}
		}
		return -1;
	}
	
	//在index位置，插入元素e，时间复杂度 O(m+n)
	public void add(int index ,T e){
		checkIndex(index);
		
		if(size == data.length){
			resize(data.length*2);
		}
		
		for (int i = size-1; i>=index; i--) {
			data[i+1] = data[i];
		}
		data[index] = e;
		size++;
	}
	
	//向数组头插入元素
	public void addFirst(T e){
		add(0,e);
	}
	
	//向数组插入最后一个元素
	public void addList(T e){
		add(size,e);
	}
	
	//删除index位置的元素，并返回
	public T remove(int index){
		checkIndex(index);
		
		T ret = data[index];
		
		for(int i = index+1; i<size; i++){
			data[i-1] = data[i];
		}
		
		size--;
		data[size] = null;
		
		//缩容    缩容的容量是否够现在的数组存放数量，data.length/4 如果等于数组的个数
		if(size == data.length/4  && data.length/2!=0){
			resize(data.length/2);
		}
		
		return ret;
	}
	
	
	@Override
	public String toString() {
		StringBuilder builder = new StringBuilder();
		builder.append(String.format("Array size = %d capacity = %d \n", size,data.length));
		builder.append('[');
		for(int i =0; i<size; i++){
			builder.append(data[i]);
			if(i!= size-1){
				builder.append(", ");
			}
		}
		builder.append(']');
		return builder.toString();
	}
	
	
	
	//扩容方法，时间复杂度O（n）
	private void resize(int capacity){
		T[] newData = (T[])new Object[capacity];
		
		for (int i = 0; i < size; i++) {
			newData[i] = data[i];
		}
		
		data = newData;
	}
	
	//删除第一个元素
	public T removeFirst(){
		return remove(0);
	}
	
	public T removeLast(){
		return remove(size-1);
	}
	
	
	
	
	
	private void checkIndex(int index){
		if(index<0 || index>data.length){
			throw new IllegalArgumentException("Add failed! Require index >=0 and index <= size.");
		}
	}
	
	private void checkIndexForRemove(int index){
		if(index>0 || index>=data.length){
			throw new IllegalArgumentException("remove failed! Require index >=0 and index < size.");
		}
	}
}
