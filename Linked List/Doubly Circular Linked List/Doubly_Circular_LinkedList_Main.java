import java.lang.*;
import java.util.*;

//Node of a doubly circular linked list.
class node
{
	String str;
	node next;
	node prev;
	
	//Parameterized Constructor
	node(String s)
	{
		this.str = s;
		this.next = null;
		this.prev = null;
		//System.out.println(str + " " + next + " " + prev);
	}
}

//Class of a doubly circular linked list.
class Doubly_Circular_LinkedList
{
	//Head pointer of Doubly Circular LinkedList.
	private node head;
	
	//Default Constructor
	Doubly_Circular_LinkedList()
	{
		head = null;
	}
	
	//Checking for linked list is empty or not.
	boolean isEmpty()
	{
		if(head == null)
			return true;
		else
			return false;
	}
	
	//Count number of elements from linked list.
	int count()
	{
		if(isEmpty())
		{
			System.out.println("Sorry. Linkedlist is empty..!\n");
			return 0;
		}
		int cnt = 0;
		node temp = head;
		
		do
		{
			cnt++;
			temp = temp.next;
		}while(temp != head);
		return cnt;
	}
	
	//Searching for specific element from linked list.
	boolean search(String s)
	{
		if(isEmpty())
		{
			System.out.println("Sorry. Linkedlist is empty..!\n");
			return false;
		}
		
		node temp = head;
		do
		{
			if(s.equals(temp.str))
				return true;
			temp = temp.next;
		}while(temp != head);
		
		return false;
	}
	
	//Inserting string at start.
	void insertAtFirst(String s)
	{
		//Creating new node.
		node newNode = new node(s);
		
		//If linked list is empty or not.
		if(isEmpty())
		{
			//Creating a new node.
			head = newNode;
			head.prev = head;
			head.next = head;
		}
		else
		{
			//Making linking of prev and next pointer.
			newNode.next = head;
			head.prev.next = newNode;
			newNode.prev = head.prev;
			head.prev = newNode;
			head = newNode;
		}
		System.out.println("Element inserted successfully..!\n");
	}
	
	//Inserting string at last.
	void insertAtLast(String s)
	{
		node newNode = new node(s);
		
		//If linked list is empty or not.
		if(isEmpty())
		{
			//Creating a new node.
			head = newNode;
			head.prev = head;
			head.next = head;
		}
		else
		{
			node temp = head.prev;
			newNode.next = head;
			head.prev = newNode;
			newNode.prev = temp;
			temp.next = newNode;
		}
		System.out.println("Element inserted successfully..!\n");
	}
	
	//Inserting string at any position.
	void insertAtPos(String s, int pos)
	{
		int len = count();

		//Checking for pos is valid or not.
		if((pos < 1 || pos > len + 1))
		{
			System.out.println("Please enter correct position.\n");
			return;
		}
		
		//If position is 1, then call insertAtFirst function.
		if(pos == 1)
		{
			insertAtFirst(s);
		}
		//If position is last, then call insertAtLast function.
		else if(pos == (len + 1))
		{
			insertAtLast(s);
		}
		else
		{
			node newNode = new node(s), temp = head;
			int i = 1;
			
			while(i < pos - 1)
			{
				temp = temp.next;
				i++;
			}
			
			newNode.next = temp.next;
			temp.next.prev = newNode;
			newNode.prev = temp;
			temp.next = newNode;
			System.out.println("Element inserted successfully..!\n");
		}
	}
	
	//Delete first element from Linked list.
	void deleteFirst()
	{
		//If linked list is empty.
		if(isEmpty())
		{
			System.out.println("Sorry. You can't delete. Linkedlist is empty..!\n");
			return;
		}
		//If there is only one element.
		else if(head.next == head)
		{
			head = null;
		}
		//If linked list contains more than one node.
		else
		{
			node temp = head;
			head.prev.next = head.next;
			head.next.prev = head.prev;
			head = head.next;
			temp = null;
		}
		System.out.println("Element deleted successfully...!!\n");
	}
	
	//Delete last element from Linked list.
	void deleteLast()
	{
		//If linked list is empty.
		if(isEmpty())
		{
			System.out.println("Sorry. You can't delete. Linkedlist is empty..!\n");
			return;
		}
		//If there is only one element.
		else if(head.next == head)
		{
			head = null;
		}
		//If linked list contains more than one node.
		else
		{
			node temp = head;
			while(temp.next != head)
			{
				temp = temp.next;
			}
			temp.prev.next = temp.next;
			temp.next.prev = temp.prev;
			temp = null;
		}
		System.out.println("Element deleted successfully...!!\n");
	}

	//Delete the element at given pos from Linked list.
	void deleteAtPos(int pos)
	{
		//If linked list is empty.
		if(isEmpty())
		{
			System.out.println("Sorry. You can't delete. Linkedlist is empty..!\n");
			return;
		}
		
		int cnt = count();
		//Checking for invalid position.
		if(pos < 1 || pos > cnt)
		{
			System.out.println("Please enter correct position.\n");
			return;
		}
		
		//If position is 1, then call deleteFirst function.
		if(pos == 1)
		{
			deleteFirst();	
		}
		//If position is last, then call deleteLast function.
		else if(cnt + 1 == pos)
		{
			deleteLast();
		}
		else
		{
			node temp = head;
			int i = 1;
			
			while(i != pos)
			{
				temp = temp.next;
				i++;
			}
			temp.next.prev = temp.prev;
			temp.prev.next = temp.next;
			temp = null;
		}
		System.out.println("Element deleted successfully...!!\n");
		
	}
	
	//Delete specific element.
	void deleteByValue(String s)
	{
		//If linked list is empty.
		if(isEmpty())
		{
			System.out.println("Sorry. You can't delete. Linkedlist is empty..!\n");
			return;
		}
		
		//If str of head is equal to given s then call deleteFirst().
		if(s.equals(head.str))
		{
			deleteFirst();
			return;
		}

		node temp = head;
		//Iterate till str of temp is not equal to s and next reference of temp is not equal to null.			
		while(temp.next != head && (s.equals(temp.str) == false))
		{
			temp = temp.next;
		}
		
		//If s is not equal to str, it means given value is not present in the linkedlist.
		if(s.equals(temp.str) == true)
		{
			temp.next.prev = temp.prev;
			temp.prev.next = temp.next;
			temp = null;
		}
		else
		{
			System.out.println(s + " is not present in the linked list..!!\n");
			return;
		}
		System.out.println("Element deleted successfully...!!\n");
	
	}
	
	//Display the elements in forward direction.
	void forward_traverse()
	{
		if(isEmpty())
		{
			System.out.println("Sorry. Linkedlist is empty..!\n");
			return;	
		}
		node temp = head;
		
		do
		{
			System.out.println(temp.str);
			temp = temp.next;
		}while(temp != head);
	}
	
	//Display the elements in forward direction.
	void backward_traverse()
	{
		if(isEmpty())
		{
			System.out.println("Sorry. Linkedlist is empty..!\n");
			return;	
		}
		
		node temp = head.prev;
		
		while(temp != head)
		{
			System.out.println(temp.str);
			temp = temp.prev;
		}
		System.out.println(temp.str);
	}
	
}

class Doubly_Circular_LinkedList_Main
{
	public static void main(String args[])
	{
		System.out.println("\n\n**************Doubly Linear LinkedList**************\n\n");
		Scanner sobj = new Scanner(System.in);
		int choice = 0, cnt = 0, pos = 0, val = 0;
		String s = "";
		Doubly_Circular_LinkedList dobj = new Doubly_Circular_LinkedList();
		while(true)
		{
			System.out.println("1.Inserting the element at FIRST position\n\n2.Inserting the element at ANY position\n\n3.Inserting the element at LAST position\n\n4.Count the elements\n\n5.Display the elements in forward direction\n\n6.Display the elements in backward direction\n\n7.Search the element\n\n8.Delete FIRST element\n\n9.Delete the element which is at specific position\n\n10.Delete LAST element\n\n11.Delete the element by VALUE\n\n0.Exit\n");
			System.out.println("Enter your choice :");
			choice = sobj.nextInt();
			
			switch(choice)
			{
				case 1:
						System.out.println("Enter your string : ");
						s = sobj.nextLine();
						s = sobj.nextLine();
						dobj.insertAtFirst(s);
						break;
						
				case 2:
						System.out.println("Enter your string : ");
						s = sobj.nextLine();
						s = sobj.nextLine();
						System.out.println("Enter the position : ");
						pos = sobj.nextInt();
						//s = sobj.nextLine();
						dobj.insertAtPos(s,pos);
						break;
						
				case 3:
						System.out.println("Enter your string : ");
						s = sobj.nextLine();
						s = sobj.nextLine();
						dobj.insertAtLast(s);
						break;
			
				case 4:
						cnt = dobj.count();
						System.out.println("Strings from the given linkedlist : " + cnt + "\n");
						break;
			
				case 5:
						System.out.println("Strings in forward direction are : ");
						dobj.forward_traverse();
						break;
						
				case 6:
						System.out.println("Strings in backward direction are : ");
						dobj.backward_traverse();
						break;
						
				case 7:
						System.out.println("Enter the string that you want to search : ");
						s = sobj.nextLine();
						s = sobj.nextLine();
						if(dobj.search(s))
							System.out.println(s + " is found in the linked list...!!\n");
						else
							System.out.println(s + " is not present in the linked list..!!\n");
						break;
				
				case 8:
						System.out.println("Deleting FIRST string...");
						dobj.deleteFirst();
						break;
						
				case 9:
						System.out.println("Enter the position to delete the string : ");
						pos = sobj.nextInt();
						s = sobj.nextLine();
						dobj.deleteAtPos(pos);
						break;
						
				case 10:
						System.out.println("Deleting LAST string...");
						dobj.deleteLast();
						break;
				
				case 11:
						System.out.println("Enter the string that you want to delete : ");
						s = sobj.nextLine();
						s = sobj.nextLine();
						dobj.deleteByValue(s);
						break;
				
				case 0:
						System.out.println("Deleting the object...!");
						dobj = null;
						System.exit(0);
				default:
						System.out.println("WRONG CHOICE..!");
					
			}
			
		}
	}
}
