package com.node;


public class Node {
	public int data;   //存储数据域
	public Node next;   //存储指针域
	
	public Node(int data ,Node next){
		this.data = data;
		this.next = next;
	}
	
	public int getData(){
		return data;
	}

}
