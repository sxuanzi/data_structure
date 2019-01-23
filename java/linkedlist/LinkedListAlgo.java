package com.linkedlist;

import com.node.Node;
/**
 * 实现链表的反转
 * 检查环
 * 有序链表合并
 * 删除倒数第K个节点
 * @author xuan
 *
 */
public class LinkedListAlgo {
	
	public static Node reverse(Node list){
		Node headNode = null;
		
		Node previousNode = null;
		Node currentNode = list;   //当前节点
		
		/**
		 * 将下个节点保存下来
		 * 将当前节点指向上一个节点
		 * 再将当前节点记录下来
		 * 再让下个节点变为当前节点
		 */
		while(currentNode !=null){
			//将下个节点保存下来
			Node nextNode = currentNode.next;
			
			if(nextNode == null){
				headNode = currentNode;
			}
			
			//将当前节点指向上一个节点
			currentNode.next = previousNode;
			//再将当前节点记录下来
			previousNode = currentNode;
			//再让下个节点变为当前节点
			currentNode = nextNode;
		}
		
		return headNode;
	}
	
	/**
	 * 需要一个Faster和Slower的概念，快慢指针
	 * Slower每次一步，Faster每次走两步
	 * 如果有环那么slower和faster就会相遇
	 * 比方：在操作跑圈，一个快一个慢，他们两个肯定会相遇
	 * 假设Faster确实把Slower超了，而且他两还没有相遇，
	 * 那么假设Faster现在在i+1位置而Slower在i位置,
	 * 那么前一刻，Slower肯定是在i-1位置，而Faster肯定在(i+1)-2,所以前一刻他们就已经相遇了
	 * 
	 * @param list
	 * @return
	 */
	 public static boolean checkCircle(Node list) {
		 if(list==null){
			 return false;
		 }
		 
		 Node fast = list.next;
		 Node slow = list;
		 if(fast !=null && fast.next!=null){
			 
			 slow = slow.next;
			 fast = fast.next.next;
			 
			 if(fast==slow){
				 return true;
			 }
			 
		 }
		return false;
		 
	 }
	 /**
	  * 首先判断lb或者la是否有一个是空链表，如果有一个空链表只需要返回一个链表回去就好
	  * 如果不是：则将la的第一个节点和lb和第一个节点比较，将数据大的节点作为首节点，传给head;
	  * 
	  * 通过while循环比较la和lb节点的大小，将两个链表比较后的内容存储到r里面
	  * 注意：r每存储一次数据，要将r要指向下一个节点  ，如果没有指向那么r的数据永远只有一个
	  * 比较到最后，可能会有一个数据剩下，需要再通过if判断一下
	  * 
	  * @param la
	  * @param lb
	  * @return
	  */
	public static Node mergeSortedLists(Node la, Node lb) {
		if(la==null) return lb;
		if(lb==null) return la;
		
		Node p = la;
		Node q = lb;
		Node r = null;
		if(p.data < p.data){
			r = q;
			p = q.next;
		}else{
			r = p;
			r = p.next;
		}
		Node head = r;
		
		while(q!=null && p!=null){
			if(q.data < p.data){
				r.next = p.next;
				p = p.next;
			}else{
				r.next = q.next;
				q = q.next;
			}
			r = r.next;
		}
		
	    if (p != null) {
	        r.next = p;
	      } else {
	        r.next = q;
	      }
		
		
		return head;
		
	}
	
	public static Node deleteLastKth(Node node, int k) {
	    Node fast = node;
	    int i = 1;
	    while (fast != null && i < k) {
	      fast = fast.next;
	      ++i;
	    }

	    if (fast == null) return node;

	    Node slow = node;   
	    Node prev = null;
	    //  1 2 3 4 5 
	    while (fast.next != null) {
	      fast = fast.next;
	      prev = slow;
	      slow = slow.next;
	    }

	    if (prev == null) {
	      node = node.next;
	    } else {
	      prev.next = prev.next.next;
	    }
	    return node;
	  }
	
	public static void printfAll(Node head){
		Node p = head.next;
		while(p!=null){
			System.out.print(p.data);
			p = p.next;
		}
	}

	
	public static void main(String[] args) {
		LinkeList list = new LinkeList();
		list.add(1);
		list.add(2);
		list.add(3);
		list.add(4);
		list.add(5);
		list.add(6);
		LinkedListAlgo.deleteLastKth(list.getHead(),2);
		printfAll(list.getHead());
	}
}
