#In Linear queue, Elements are always added to the back and removed from the front.
class Queue:
    #Set rear and front to -1 and max_size to 10
    rear = -1; front = -1; max_size = 5;

    #default constructor.
    def __init__(self):
        self.arr = [self.max_size] * 0

    #isEmpty : function checks that given array is empty or not by using rare and front variables.
    def isEmpty(self):
        if (((self.rear == -1) and (self.front == -1)) or (self.rear == self.front)):
            return True
        else:
            return False
    
    #isFull : function checks that given array is full or not by using rare variable.
    def isFull(self):
        if self.rear == self.max_size - 1:
            return True
        else:
            return False
    
    #enqueue : If the queue is not full, this function adds an element to the back of the queue, else it prints “OverFlow”.
    def enqueue(self, value):
        if self.isFull() == True:
            print("Queue is OverFlow...So you can't add.")
            return
        else:
            self.rear += 1
            self.arr.append(value)
            print("Element {0} inserted successfully.".format(value))
            print()

    #dequeue : If the queue is not empty, this function removes the element from the front of the queue, else it prints “UnderFlow”.
    def dequeue(self):
        if self.isEmpty() == True:
            print("Queue is UnderFlow...So you can't remove.")
            return 
        else:
            self.front += 1
            no = self.arr.pop(0)
            print("Removed element : {0} \nElement removed successfully.".format(no))
            print()

#main() function.
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

    print("Queue after inserting 5 elements : ", qobj.arr)
    print()

    print("Trying to insert 6th element into queue of capacity 5...")
    qobj.enqueue(60)

    print("Queue after trying to insert the 6th element : ", qobj.arr)
    print()

    #Removing values from queue.
    qobj.dequeue()
    qobj.dequeue()
    qobj.dequeue()
    qobj.dequeue()
    qobj.dequeue()
        
    print("Trying to remove 6th element into queue of capacity 5...")
    qobj.dequeue()

    print("Queue after inserting 5 elements : ", qobj.arr)
    print()

# It's as if the interpreter inserts this at the top of your module when run as the main program.
if __name__ == "__main__":
    main()