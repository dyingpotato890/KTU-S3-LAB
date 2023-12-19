import java.util.Scanner;

class node{
	int data;
	node next;
	node prev;
}

class DLL{
	static Scanner s = new Scanner(System.in);
	
	static node head = null;
	static node ptr = null;
	
	public static void insert(){
		node newNode = new node();
		ptr = head;

		System.out.print("\nEnter The Node Data: ");
		newNode.data = s.nextInt();
		
		if(head == null){
			head = ptr = newNode;
			head.next = newNode.prev = null;	
		}
		else{	
			while (ptr.next != null)
				ptr = ptr.next;
			newNode.prev = ptr;
			newNode.next = null;
			ptr.next = newNode;
		}
		System.out.println("Element Inserted!\n");
	}
	
	public static void delete(){
		ptr = head;
		if (head == null)
			System.out.println("List Empty!");
		else{
			while (ptr.next != null)
				ptr = ptr.next;
			
			System.out.println("Deleted Element: " + ptr.data);
			if (ptr == head)
				ptr = head = null;
			else
				ptr.prev.next = null;
		}
	}
	
	public static void display(){
		if (head == null)
			System.out.println("List Empty!");
		else{
			node ptr = head;
			System.out.println("List Contents:");
			while (ptr != null){
				System.out.print(ptr.data + " --> ");
				ptr = ptr.next;
			}
			System.out.print("NULL");
		}
	}
	
	public static void main(String args[]){		
		int flag = 1;
		
		System.out.println("======== MENU ========");
		System.out.println("1) Insert");
		System.out.println("2) Delete");
		System.out.println("3) Display");
		System.out.println("4) Exit");
		System.out.println("======================");
		
		while(flag == 1){
			int o;
			System.out.print("\nEnter Your Option: ");
			o = s.nextInt();
			
			switch(o){
				case 1:
					insert();
					break;
				case 2:
					delete();
					break;
				case 3:
					display();
					break;
				case 4:
					flag = 0;
					break;
				default:
					System.out.println("Enter A Valid Option!");
			}
		}
	}
}