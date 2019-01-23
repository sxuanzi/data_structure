package com.linkedlist;

import com.node.Node;

/**
 * 无头节点的链表
 * @author xuan
 *
 */
public class SinglyLinkedList {
	
	private Node head = null;
	
	
	public void insertToHead(int value){
		Node newNode = new Node(value,null);
		insertToHead(newNode);
	}
	
	
	//逆序
	public void insertToHead(Node newNode){	
		if(head==null){
			head = newNode;
		}else{
			//1  1（第三个节点）  2（第二个节点）  3（第一个节点）
			newNode.next = head;
			head = newNode;
		}	
	}
	
	public void insertTail(int value){
		Node newNode = new Node(value,null);
		if(head == null){
			head = newNode;
		}else{
			Node q = head;
			while(q.next!=null){
				q = q.next;
			}
			
			newNode.next = q.next;
			q.next = newNode;
			
		}
	}
	
	public void insertAfter(Node p, int value){
		Node newNode = new Node(value, null);
		insertAfter(p,newNode);
	}
	
	//在某个节点之后插入
	public void insertAfter(Node p, Node newNode){
		if(p==null)
			return;
		
		newNode.next = p.next;
		p.next = newNode;
	}
	
	public void insertBefore(Node p, int value){
		Node newNode = new Node(value, null);
		insertBefore(p,newNode);
	}
	
	public void insertBefore(Node p, Node newNode){
		
		if(p==null)
			return;
		
		if(head == p){
			insertToHead(newNode);
			return;
		}
		
		Node q = head;
		while(q !=null && q.next != p){
			q = q.next;
		}
		
		if(q == null){
			return;
		}
		
		newNode.next = p;
		q.next = newNode;
		
		
	}
	
	
	
	public boolean TFResult(Node leftLink, Node rightLink){
		Node l= leftLink;
		Node r = rightLink;
		
		System.out.println("left_:"+l.data);
		System.out.println("right_:"+r.data);
		
		while(l !=null && r!=null){
			if(l.data == r.data){
				l = l.next;
				r = r.next;
				continue;
			}else{
				break;
			}
		}
		
		System.out.println("什么结果");
		if(l==null && r==null){
			return true;
		}else{
			return false;
		}
	}
	
	public Node inverseLinkList(Node p){
		Node pre = null;
		Node r = head; 
		
		System.out.println("z---" + r.data);
		Node next = null;
		while(r != p){   
			// r: 1 2 5   r:2 5 3 (1保存在pre)   r:5 3 1(2保存在pre)   r:5 2 1
			next = r.next;

            r.next = pre;
            pre = r;
            r = next;
		}
		
		
		 r.next = pre;
		return r;
	}
	
	public boolean palindrome(){
		if(head == null){
			return false;
		}else{
			System.out.println("开始指向找到中间节点");
			
			Node p = head;
			Node q = head;
			
			if(p.next ==null){
				  System.out.println("只有一个元素");
	               return true;
			}
			
			while(q.next!=null && q.next.next !=null){
				p = p.next;  //指向中间节点
				q = q.next.next;   //指向最后一个节点
			}
			
			System.out.println("中间节点"+p.data);
			System.out.println("开始执行奇数节点的回文判断");
			Node leftLink = null;
			Node rightLink = null;
			
			if(q.next ==null){
				rightLink = p.next;
				leftLink = inverseLinkList(p).next;
				
				 System.out.println("左边第一个节点"+leftLink.data);
	             System.out.println("右边第一个节点"+rightLink.data);
			}else{
				rightLink = p.next;
				leftLink = inverseLinkList(p);
			}
			return TFResult(leftLink, rightLink);
		}
		
	}
	
	public void printfAll(){
		Node p = head;
		while(p!=null){
			System.out.print(p.data);
			p = p.next;
		}
	}
	
	
	public static void main(String[] args) {
		  SinglyLinkedList link = new SinglyLinkedList(); 
	        int data[] = {1,2,5,3,1};

	        for(int i =0; i <data.length; i++){
	            //link.insertToHead(data[i]);
	            link.insertTail(data[i]);
	        }
	        
	        link.printfAll();
	        
	        System.out.println("打印原始:");
	        link.printfAll();
	        if (link.palindrome()){
	            System.out.println("回文");
	        }else{
	            System.out.println("不是回文");
	        }
	}
	

}
