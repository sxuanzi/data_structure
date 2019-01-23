package com.stack;

/**
 * 实现浏览器的前进和后退
 * @author xuan
 *
 */
public class SampleBrowser {
	
	   public static void main(String[] args) {
	        SampleBrowser browser = new SampleBrowser();
	        browser.open("http://www.baidu.com");
	        browser.open("http://news.baidu.com/");
	        browser.open("http://news.baidu.com/ent");
	        browser.goBack();
	        browser.goBack();
	        browser.goForward();
	        browser.open("http://www.qq.com");
	        browser.goForward();
	        browser.goBack();
	        browser.goForward();
	        browser.goBack();
	        browser.goBack();
	        browser.goBack();
	        browser.goBack();
	        browser.checkCurrentPage();
	    }
	
	private String currentPage;
	private LinkedListBaseStack backStack;
	private LinkedListBaseStack forwardStack;
	
	public SampleBrowser(){
		this.forwardStack = new LinkedListBaseStack();
		this.backStack = new LinkedListBaseStack();
	}
	
	public void open(String url){
		if(this.currentPage != null){
			this.backStack.push(this.currentPage);
			this.forwardStack.clear();
		}
		showUrl(url,"Open");
	}
	
	public boolean canGoBack(){
		return this.backStack.size >0 ;
	}
	
	public boolean canGoForward(){
		return this.forwardStack.size > 0;
	}
	
	
	public String goBack(){
		if(this.canGoBack()){
			this.forwardStack.push(this.currentPage);
			String backUrl = this.backStack.pop();
			showUrl(backUrl, "Back");
			return backUrl;
		}
		System.out.println("* Cannoy go back, no pages behind");
		return null;
	}
	
	public String goForward(){
		if(this.canGoForward()){
			this.backStack.push(this.currentPage);
			String forwardUrl = this.forwardStack.pop();
			showUrl(forwardUrl,"Foward");
			return forwardUrl;
		}
		System.out.println("* Cannnoy go forward, no pages ahead ");
		return null;
	}
	
	
	
	public void showUrl(String url, String prefix){
		 this.currentPage = url;
		 System.out.println(prefix + " page == " + url);
	}
	
	public void checkCurrentPage(){
		System.out.println("Current page is:"+this.currentPage);
	}
	public static class LinkedListBaseStack{
		private static int size;
		private static Node top = null;
		
		static Node createNode(String data, Node next){
			Node node = new Node(data,next);
			return node;
		}
		
		public void clear(){
			this.top = null;
			//为什么要加一
			this.size++;
		}
		
		public void push(String data){
			Node node = createNode(data,this.top);
			this.top = node;
			this.size++;
		}
		
		public String pop(){
			Node popNode = this.top;
			if(popNode == null){
				System.out.println("Stack is empty");
				return null;
			}
			
			this.top = top.next;
			if(this.size > 0){
				this.size--;
			}
			return popNode.data;
		}
		
		public String getTopData(){
			if(this.top == null){
				return null;
			}
			return this.top.data;
		}
		public static class Node{
			private String data;
			private Node next;
			
			Node(String data, Node next){
				this.data = data;
				this.next = next;
			}

			public String getData() {
				return data;
			}

			public void setData(String data) {
				this.data = data;
			}

			public Node getNext() {
				return next;
			}

			public void setNext(Node next) {
				this.next = next;
			}
			
			
			
		}
	}

}
