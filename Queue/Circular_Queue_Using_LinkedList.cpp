//Circular Queue using LinkedList.
#include<iostream>
using namespace std;

//node class.
class Node
{
    public:
        int data;
        Node *next;   

        //Default Constructor.
        Node(int data)
        {
            this -> data = data;
            this -> next = NULL;
        }    
};

//Circular Queue Class.
class CircularQueue
{
    public:
        //Creating rear and front pointer.
        Node *rear, *front;

        //Default Constructor.
        CircularQueue()
        {
           rear = front = NULL;
        }

        //Functions.
        bool isEmpty();
        void enqueue(int);
        void displayQueue();
        int dequeue();
};

//isEmpty : function checks that given queue is empty or not by using rear and front pointers.
bool CircularQueue :: isEmpty()
{
    if(rear == NULL and front == NULL)
        return true;
    return false;
}

//enqueue : this function adds an element to the queue.
void CircularQueue :: enqueue(int data)
{
    //Create new node
    Node *newNode = new Node(data);

    //If linkedlist is empty
    if(isEmpty())
    {
        rear = front = newNode;
    }
    else
    {
        Node *temp = rear;
        rear -> next = newNode;
        newNode -> next = front;
        rear = newNode;
    }
    rear -> next = front;
    cout << endl << data << " inserted successfully.\n";

}

//displayQueue : this function displays whole the queue.
void CircularQueue :: displayQueue()
{
    //Creating Node for traversal. 
    Node *temp = front;
    do
    {
        cout << temp -> data << endl;
        temp = temp -> next;
    }while(temp != rear -> next);
}

//dequeue : If the queue is not empty, this function removes the element from the queue, else returns -1.
int CircularQueue :: dequeue()
{
    if(isEmpty())
        return -1;

    Node *temp = front;
    int val = temp -> data;
    front = front -> next;
    rear -> next = front;

    delete temp;

    return val;
}

//Entry Point function.
int main()
{
    cout << "\n********** Queue Data Structure **********\n";

    CircularQueue *cobj = new CircularQueue();

    //Inserting values into queue.
    cobj -> enqueue(10);
    cobj -> enqueue(20);
    cobj -> enqueue(30);
    cobj -> enqueue(40);
    cobj -> enqueue(50);

    cout << "\nQueue after inserting 5 elements : \n";
    cobj -> displayQueue();

    //Removing values from queue.
    cout << "\nRemoved Element : " << cobj -> dequeue() << endl;
    cout << "Element removed successfully.\n";
    
    cobj -> enqueue(60);

    cout << "\nQueue after removing and inserting all elements : \n";
    cobj -> displayQueue();

    cout << "\nRemoved Element : " << cobj -> dequeue() << endl;
    cout << "Element removed successfully.\n";

    cout << "\nRemoved Element : " << cobj -> dequeue() << endl;
    cout << "Element removed successfully.\n";

    cobj -> enqueue(70);

    cout << "\nQueue after removing and inserting all elements : \n";
    cobj -> displayQueue();

    cout << "\nRemoved Element : " << cobj -> dequeue() << endl;
    cout << "Element removed successfully.\n";

    cout << "\nRemoved Element : " << cobj -> dequeue() << endl;
    cout << "Element removed successfully.\n";

    cout << "\nQueue after removing and inserting all elements : \n";
    cobj -> displayQueue();

    //Removing and inserting new values.
    cobj -> enqueue(80);
    cobj -> enqueue(90);

    cout << "\nRemoved Element : " << cobj -> dequeue() << endl;
    cout << "Element removed successfully.\n";

    cobj -> enqueue(100);

    cout << "\nNow, Final Queue is : \n";
    cobj -> displayQueue();

    return 0;   
}
