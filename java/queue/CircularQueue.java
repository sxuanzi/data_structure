package com.queue;

public class CircularQueue {
	
	private int head = 0;
	private int tail = 0;
	private int n = 0;
	private String[] items;
	
	public CircularQueue(int capacity) {
		items = new String[capacity];
		n = capacity;
	}
	
	 public boolean enqueue(String str){
		 if((tail +1 ) % n == head) return false;
		 items[tail] = str;
		 tail = (tail + 1) % n;
		 return true;
	 }
	 
	 public String dequeue(){
		 if(tail == head) return null;
		 String ret = items[head];
		 head = (head + 1) % n;
		 return ret;
	 }
	 
	 public void printAll(){
		 int i = head;
		 while(i!=tail){
			 System.out.print(items[i]+","); 
			  i = (i+1)%n;
		 }
		 System.out.println();
	 }
	 
	 public static void main(String[] args) {
		 /**
		  * 注意，循环队列有一个元素是不可以使用的，是用来判断的
		  */
		CircularQueue circular = new CircularQueue(5);
		circular.enqueue("你好");
		circular.enqueue("你好1");
		circular.enqueue("你好2");
		circular.dequeue();
		circular.enqueue("你好3");
		circular.dequeue();
		circular.enqueue("你好4");
		circular.dequeue();
		circular.enqueue("你好5");
		circular.printAll();
	 }
}
