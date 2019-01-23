package com.linkedlist;

import com.node.Node;;
/**
 * 有头节点的链接
 * @author xuan
 *
 */
public class LinkeList {
	private Node head = null; 
	private Node pTail = null;
	
	LinkeList(){
		head = new Node(0, null);
		pTail = head;
	}
	

	public void add(int value){
		Node newNode = new Node(value, null);
		
		Node p = head;
		while(p.next !=null){
			p = p.next;
		}
		
		p.next = newNode;
		
	}
	
	public int add(int value, int index){
		Node newNode = new Node(value, null);
		
		Node p = head;
		
		for(int i=1; p.next!=null; i++){
			p = p.next;
			if(i==index){
				newNode.next = p.next;
				p.next = newNode;
				
				return 1;
			}
		}
		
		return -1;
		
	}
	
	public void addFirst(int value){
		Node newNode = new Node(value, null);
		
		Node p = head;
		
		newNode.next = head.next;
		head.next = newNode;
		
	}
	
	public void addLast(int value){
		Node newNode = new Node(value, null);
		
		Node p = head;
		while(p.next != null){
			p = p.next;
		}
		
		p.next = newNode;
	}
	
	public void printfAll(){
		Node p = head.next;
		while(p!=null){
			System.out.print(p.data);
			p = p.next;
		}
	}	

	public Node getHead() {
		return head;
	}
	
	public static void main(String[] args) {
		LinkeList list = new LinkeList();
		list.add(1);
		list.add(1);
		list.add(1);
		list.add(2, 1);
		list.addFirst(2);
		list.addLast(3);
		list.printfAll();
	}
}
