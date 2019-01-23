package com.queue;

public class ArrayQueue {
	
	private int head = 0;
	private int tail = 0;
	private int size = 0;
	private int[] items;
	
	ArrayQueue(int capacity){
		items = new int[capacity];
		size = capacity;
	}
	
	//入队
	public boolean enqueue(int data){
		if(head==size) return false;
		items[tail] = data;
		tail++;
		return true;
	}
	
	//出队
	public int dequeue(){
		if(head==tail) return -1;
		int result= items[head];
		head++;
		return result;
		
	}
	
	public void printAll(){
		for (int i = head; i < tail; i++) {
			System.out.println(items[i]+",");
		}
	}
	
	public static void main(String[] args) {
		ArrayQueue queue = new ArrayQueue(10);
		if(queue.dequeue()==-1){
			System.out.println("队列为空");
		}
		queue.printAll();
	}

}
