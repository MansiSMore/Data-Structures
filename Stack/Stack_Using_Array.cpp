//A stack is an ordered data structure in which insertion and deletion done at one end, called top.
//Implementation of stack data structure using Array.
#include <iostream>
#include <cstring>
#define MAX 10
using namespace std;

class Stack
{
	//Characteristics
	public:
			int arr[10], top;
	
	//Behaviour
	public:
			//Default constructor
			Stack();
			
			//Functions
			bool isEmpty();
			bool isFull();
			void push(int);
			int pop();
			int length();
};

//Function definitions of Stack Class

//Default Constructor
Stack :: Stack()
{
	arr[10] = {0};
	top = -1;
}

//isEmpty function checks that given array is empty or not by using top variable.
//If stack is empty, then value of top is -1.
bool Stack :: isEmpty()
{
	if(top < 0)
		return true;
	else
		return false;
}

//isFull function checks that given array is full or not by using top variable.
//If stack is full, then value of top is equal to length of array minus 1.
bool Stack :: isFull()
{
	if(top >= (MAX - 1))
		return true;
	else
		return false;
}

//push function push the value in array if stack is not overflow.
void Stack :: push(int val)
{
	if(isFull() == true)
	{
		cout << "Stack is overflow now. You can't push the value.\n";
		return;
	}
	top++;
	//cout << top << " top \n";
	arr[top] = val;
	cout << val << " inserted successfully..!\n";
}

//pop function removes the value from top if the stack is not underflow.
int Stack :: pop()
{
	if(isEmpty() == true)
	{
		cout << "Stack is underflow now. You can't pop the value.\n";
		return 0;
	}
	
	int val = arr[top];
	top--;
	return val;
}
 
//length function returns number of elements from stack.
int Stack :: length()
{
	int i = top, cnt = 0;
	
	while(i != -1)
	{
		cnt++;
		i--;
		//cout << cnt << " " << i << endl;
	}
	
	return cnt;
}

//Entry point function.
int main()
{
	//Creating the object of Stack class.
	Stack sobj;
	
	cout << "********** Stack Data Structure **********\n\n";
	//Inserting values into stack.
	sobj.push(10);
	sobj.push(20);
	sobj.push(30);
	sobj.push(40);
	sobj.push(50);
	
	cout << "Length of stack after push : " << sobj.length() << endl;
	//cout << "top : " << sobj.top << endl;
	cout << sobj.pop() << "\n";
	cout << sobj.pop() << "\n";
	
	cout << "Length of stack after pop : " << sobj.length() << endl;
	cout << sobj.length() << endl;
	//cout << sobj.length() << endl;
	//cout << sobj.isEmpty() << endl;
	//cout << sobj.isFull() << endl;
	return 0;
}
