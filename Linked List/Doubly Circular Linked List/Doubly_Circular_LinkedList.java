import java.lang.*;
import java.util.*;

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
		System.out.println(str + " " + next + " " + prev);
	}
}

class Doubly_Circular_LinkedList
{
	//Head pointer of Doubly Circular LinkedList.
	private node head = null;
	
	//Parameterized Constructor
	Doubly_Circular_LinkedList(String s)
	{
		super(s);
		System.out.println(super.s);
	}
	
	bool isEmpty()
	{
		if(head == null)
			return true;
		else
			return false;
	}
	
	void insertFirst()
	{
		/*if(isEmpty())
		{
			node newNode = new newNode();
		}*/
		System.out.println("Mansi..!");
	}
	
}

class Doubly_Circular_LinkedList_Main
{
	public static void main(String args[])
	{
		Doubly_Circular_LinkedList dobj = new Doubly_Circular_LinkedList("More");
		//dobj.insertFirst();
	}
}
