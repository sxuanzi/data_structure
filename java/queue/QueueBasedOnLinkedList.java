package com.queue;

public class QueueBasedOnLinkedList {
	
	private Node head;
	private Node tail;
	
	
	public void enqueue(int data){
		
		if(head==null){
			Node node = new Node(data,null);
			tail = node;
			head = node;	
		}else{
			Node newNode = new Node(data,null);
			tail.next = newNode;
			tail = tail.next;
		}	
	}
	
	public int dequeue(){
		
		if(head==null) return -1;
		int ret = head.data;
		head = head.next;
		if (head == null) {
		      tail = null;
		 }
		return ret;
	}
	
	public void printAll(){
		Node p = head;
		while(p!=null){
			System.out.print(p.data+" ");
			p = p.next;
		}
	}
	

	static class Node {
		int data;
		Node next;
		public Node(int data, Node next) {
			super();
			this.data = data;
			next = next;
		}		
		
	}
	
	public static void main(String[] args) {
		QueueBasedOnLinkedList queue = new QueueBasedOnLinkedList();
		queue.enqueue(1);
		if(queue.dequeue()==-1){
			System.out.println("队列为空");
		}
		queue.printAll();
	}
	

}
