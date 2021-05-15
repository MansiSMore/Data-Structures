#include <iostream>
using namespace std;

//Node of a doubly linked list.
class node
{
	public :
			char data = '\0';
			node *next = NULL;
			node *prev = NULL;
};

//Class of a doubly linked list.
class DLL
{
	private : 
			//Characteristics
			node *head;
	public :
			//Behaviour
			//Default Constructor
			DLL();
			
			//Destructor
			~DLL();
			void insertAtFirst(char);
			void insertAtPos(char, int);
			void insertAtLast(char);
			void deleteFirst();
			void deleteLast();
			void deleteAtPos(int);
			void deleteByValue(char);
			bool search(char);
			int count();
			void forward_traverse();
			void backward_traverse();
			
};

//Function Definitions of DLL class.
//Default Constructor
DLL :: DLL()
{
	head = NULL;
}

//Destructor
DLL :: ~DLL()
{
	cout << "Deallocating memory...\n\n";

	node *temp1 = head;
	
	while(head != NULL)
	{
		node* temp1 = head;
		head = head -> next;
		delete temp1;
	}
	
	delete head;

}
//Count number of elements from linked list.
int DLL :: count()
{
	if(head == NULL)
	{
		cout << "Sorry. Linkedlist is empty..!\n\n";
		return 0;
	}
	
	int cnt = 0;
	node *temp = head;
	while(temp != NULL)
	{
		cnt++;
		temp = temp -> next;
	}
	return cnt;
}

//Searching for specific element from linked list.
bool DLL :: search(char ch)
{
	if(head == NULL)
	{
		cout << "Sorry. Linkedlist is empty..!\n\n";
		return false;
	}
	
	node *temp = head;
	while(temp != NULL)
	{
		if(ch == temp -> data)
			return true;
		temp = temp -> next;
	}
	return false;
}

//Inserting char element at start.
void DLL :: insertAtFirst(char ch)
{
	node *newNode = new node();
	newNode -> data = ch;
	
	//If the linked list is empty, 
	if(head == NULL)
	{
		head = newNode;
	}
	else
	{
		newNode -> next = head;
		head -> prev = newNode;
		head = newNode;
	}
	
	cout << "Element inserted successfully...!!\n\n";
}

//Inserting char element at last.
void DLL :: insertAtLast(char ch)
{
	node *newNode = new node();
	newNode -> data = ch;
	
	//If the linked list is empty, 
	if(head == NULL)
	{
		head = newNode;
	}
	else
	{
		node *temp = head;
		
		while(temp -> next != NULL)
		{
			temp = temp -> next;
		}
		
		temp -> next = newNode;
		newNode -> prev = temp;
	}
	
	cout << "Element inserted successfully...!!\n\n";
}

//Inserting char element at any position.
void DLL :: insertAtPos(char ch, int pos)
{
	int cnt = count();
	
	//Checking for invalid position.
	if(pos < 1 || (pos > (cnt + 1)))
	{
		cout << "Please enter correct position.\n\n";
		return;
	}
	
	//If position is 1, then call insertAtFirst function.
	if(pos == 1)
	{
		insertAtFirst(ch);
	}
	//If position is last, then call insertAtLast function.
	else if(cnt + 1 == pos)
	{
		insertAtLast(ch);
	}
	else
	{
		node *temp = head;
		node *newNode = new node();
		newNode -> data = ch;
		int i = 1;
		while(i != (pos - 1))
		{
			i++;
			temp = temp -> next;
		}
		
		newNode -> next = temp -> next;
		temp -> next -> prev = newNode;
		newNode -> prev = temp;
		temp -> next = newNode;	
		cout << "Element inserted successfully...!!\n\n";
	}

	
}

//Delete first element from Linked list.
void DLL :: deleteFirst()
{
	//If linked list is empty.
	if(head == NULL)
	{
		cout << "Sorry. Linkedlist is empty..!\n\n";
		return;
	}
	//If linked list contains single node.
	else if(head -> next == NULL)
	{
		head = NULL;
		delete head;
	}
	else
	{
		//Store the value of head node into temp node.
		node *temp = head;
		
		//Head moves to the next node.
		head = head -> next;
		
		//Set the prev pointer to NULL;
		head -> prev = NULL;
		
		//Delete temp now. 
		delete temp;
	}
	cout << "Element deleted successfully...!!\n\n";
}

//Delete last element from Linked list.
void DLL :: deleteLast()
{
	//If linked list is empty.
	if(head == NULL)
	{
		cout << "Sorry. Linkedlist is empty..!\n\n";
		return;
	}
	//If linked list contains single node.
	else if(head -> next == NULL)
	{
		head = NULL;
		delete head;
	}
	//If linked list contains more than one node.
	else
	{
		//Store the value of head node into temp node.
		node *temp1 = head, *temp2 = NULL;
		while(temp1 -> next != NULL)
		{
			temp1 = temp1 -> next;
		}
		temp2 = temp1;
		temp1 -> prev -> next = NULL;
		delete temp2;
		cout << "Element deleted successfully...!!\n\n";
	}

}

//Delete the element at given pos from Linked list.
void DLL :: deleteAtPos(int pos)
{
	//If linked list is empty.
	if(head == NULL)
	{
		cout << "Sorry. Linkedlist is empty..!\n\n";
		return;
	}
	
	int cnt = count();
	//Checking for invalid position.
	if(pos < 1 || pos > cnt)
	{
		cout << "Please enter correct position.\n\n";
		return;
	}
	
	//If position is 1, then call deleteFirst function.
	if(pos == 1)
	{
		deleteFirst();	
	}
	//If position is last, then call insertAtLast function.
	else if(cnt + 1 == pos)
	{
		deleteLast();
	}
	else
	{
		node *temp1 = head, *temp2 = NULL;
		int i = 1;
		while(i != (pos - 1))
		{
			i++;
			temp1 = temp1 -> next;
		}
		temp2 = temp1 -> next;
		temp1 -> next = temp1 -> next -> next;
		temp1 -> next -> prev = temp1;
		
		delete temp2;
		cout << "Element deleted successfully...!!\n\n";
	}

}

//Delete specific element.
void DLL :: deleteByValue(char ch)
{
	//If linked list is empty then don't do anything.
	if(head == NULL)
	{
		cout << "Sorry. Linkedlist is empty..!\n\n";
		return;
	}
	
	//If data of head is equal to given data then call deleteFirst().
	if(head -> data == ch)
	{
		deleteFirst();
		return;
	}
	node *temp1 = head, *temp2 = NULL;
	//Iterate till data of temp1 is not equal to ch and next pointer of temp1 is not equal to NULL.
	while(temp1 -> next != NULL && temp1 -> data != ch)
	{
		temp1 = temp1 -> next;
	}
	
	//If data is equal to ch, it means we found our targeted position.
	if(temp1 -> data == ch)
	{
		//Store the value of previous pointer in temp2.
		temp2 = temp1 -> prev;
		
		//If next pointer is not equal to NULL, then adjust next and previous pointer according to that.
		if(temp1 -> next != NULL)
		{
			temp2 -> next = temp1 -> next;
			temp1 -> next -> prev = temp2;
			//temp2 -> next = temp1;
			delete temp1;
		}
		//If next pointer is equal to NULL, then update next pointer of temp2 and delete temp1.
		else
		{
			temp2 -> next = NULL;
			delete temp1;
		}

	}
	//If data is not equal to ch, it means given value is not present in the linkedlist.
	else
	{
		cout << ch << " is not present in the linked list..!!\n";
		return;
	}
	cout << "Element deleted successfully...!!\n\n";
}

//Display the elements in forward direction.
void DLL :: forward_traverse()
{
	if(head == NULL)
	{
		cout << "Sorry. Linkedlist is empty..!\n\n";
		return;
	}

	node *temp = head;
	while(temp != NULL)
	{
		cout << temp -> data << endl;
		temp = temp -> next;
	}
	cout << endl;
}

//Display the elements in forward direction.
void DLL :: backward_traverse()
{
	if(head == NULL)
	{
		cout << "Sorry. Linkedlist is empty..!\n\n";
		return;
	}
	
	node *tail = head, *temp = head; 
	while(temp -> next != NULL)
	{
		temp = temp -> next;
	}
	tail = temp;
	while(temp != NULL)
	{
		cout << temp -> data << endl;
		temp = temp -> prev;
	}
	cout << endl;
}

int main()
{
	int i = 0 , cnt = 0 , pos = 0 , no = 0;
	char ele = '\0';
	DLL *obj = new DLL();
	
	cout << "\n\n**************Doubly Linear LinkedList**************\n\n";
	while(1)
	{
		cout << "1.Inserting the element at FIRST position\n\n2.Inserting the element at ANY position\n\n3.Inserting the element at LAST position\n\n4.Count the elements\n\n5.Display the elements in forward direction\n\n6.Display the elements in backward direction\n\n7.Search the element\n\n8.Delete FIRST element\n\n9.Delete the element which is at specific position\n\n10.Delete LAST element\n\n11.Delete the element by VALUE\n\n0.Exit\n";
		cout << "\nEnter your choice :\n";
		cin >> no;
		
		switch(no)
		{
			case 1:
					cout << "Enter the data :\n";
					cin >> ele;
					obj -> insertAtFirst(ele);
					break;
			case 2:
					cout << "Enter the data and position\n";
					cin >> ele >> pos;
					obj -> insertAtPos(ele,pos);
					break;
			case 3:
					cout << "Enter the data :\n";
					cin >> ele;
					obj -> insertAtLast(ele);
					break;
			
			case 4:
					cnt = obj -> count();
					cout << "Elements from the given linkedlist : " << cnt << endl << endl;
					break;
			
			case 5:
					cout << "Elements in forward direction are :\n";
					obj -> forward_traverse();
					break;
			case 6:
					cout << "Elements in backward direction are :\n";
					obj -> backward_traverse();
					break;
			case 7:
					cout << "Enter the character that you want to search :\n";
					cin >> ele;
					if(obj -> search(ele))
						cout << ele << " is found in the linked list...!!\n";
					else
						cout << ele << " is not present in the linked list..!!\n";
					break;
			case 8:
					cout << "Deleting FIRST element...\n";
					obj -> deleteFirst();
					break;
			case 9:
					cout << "Enter the position to delete the element:\n";
					cin >> pos;
					obj -> deleteAtPos(pos);
					break;
			case 10:
					cout << "Deleting LAST element...\n";
					obj -> deleteLast();
					break;
			
			case 11:
					cout << "Enter the char that you want to delete :\n";
					cin >> ele;
					obj -> deleteByValue(ele);
					break;
			
			
			case 0:
					delete obj;
					exit(0);
			default:
					cout << "WRONG CHOICE..!\n\n";
					
		}
	}

	return 0;
}
