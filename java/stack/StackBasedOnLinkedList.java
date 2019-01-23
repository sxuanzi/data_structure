package com.stack;

import com.node.Node;

public class StackBasedOnLinkedList {
	
	private Node head;
	
	
	 public void push(int value){
		 Node newNode = new Node(value,null);
		 
		 if(head==null){
			 head = newNode;
		 }else{
			 Node node = head;
			 head = newNode;
			 head.next = node;
		 }
	 }
	 
	 public int pop() {
		 if(head == null) return -1;
		 
		 Node newNode = head;
		 head = head.next;
		 int value = newNode.data;
		return value;
		 
	 }
	 
	 public void printAll(){
		 Node node = head;
		 while(node!=null){
			 System.out.println(node.data+",");
			 node = node.next;
		 }
		 
	 }
	 
	 public static void main(String[] args) {
		 StackBasedOnLinkedList linked = new StackBasedOnLinkedList();
		 linked.push(1);
		 linked.push(21);
		 linked.push(3);
		 linked.push(4);
		 linked.pop();
		 linked.pop();
		 linked.pop();

		 linked.printAll();
		 
	}

}
