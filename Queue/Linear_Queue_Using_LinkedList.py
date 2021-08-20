#Linear Queue using Linked list.

#node class
class node:

    def __init__ (self, data):
        self.data = data
        self.next = None
        
#Queue class
class Queue:

    #Rear and Front variables of class queue.
    def __init__(self):
        self.rear = self.front = None
    
    #isEmpty : function checks that given queue is empty or not by using rare and front variables.
    def isEmpty(self):

        if self.front == None:
            return True
        else:
            return False

    #enqueue : If the queue is empty, set front variable to the newNode, else this function adds an element to the back of the queue.
    def enqueue(self, data):

        #Create new node of Class node with given data.
        newNode = node(data)

        if(self.isEmpty()):
            self.rear = self.front = newNode 
        else:
            self.rear.next = newNode
            self.rear = self.rear.next 
        
        print("Element {0} inserted successfully.\n".format(data))
    
    #dequeue : If the queue is not empty, this function removes the element from the front of the queue, else it prints “UnderFlow”.
    def dequeue(self):

        if(self.isEmpty()):
            print("Queue is UnderFlow...So you can't remove.")
            return
        else:
            num = self.front.data
            temp = self.front
            self.front = self.front.next
            del temp
            print("Removed element : {0}.Element removed successfully.\n".format(num))

    #displayQueue : This function display all the elements from queue from start to end.
    def displayQueue(self):
        temp = self.front

        print("Elements From Queue :")
        while temp != None:
            print(temp.data)
            temp = temp.next
        print()


def main():
    #Creating the object of Queue class.
    qobj = Queue()

    print("\n********** Queue Data Structure **********\n")

    #Inserting values into queue.
    qobj.enqueue(10)
    qobj.enqueue(20)
    qobj.enqueue(30)
    qobj.enqueue(40)
    qobj.enqueue(50)

    qobj.displayQueue()

    qobj.enqueue(60)
    print("Queue after inserting the 6th element : ")
    qobj.displayQueue()

    #Removing values from queue.
    qobj.dequeue()
    qobj.dequeue()
    qobj.dequeue()
    qobj.dequeue()
    qobj.dequeue()
    qobj.dequeue()

    print("Trying to remove element from queue after removing all elements...")
    qobj.dequeue()
    print()

if __name__ == "__main__":
    main()
