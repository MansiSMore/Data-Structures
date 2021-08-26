#Circular queue.
class circularQueue:
    #Set rear and front to -1 and max_size to 10
    rear = -1; front = -1; max_size = 5;

    #default constructor.
    def __init__(self):
        self.arr = [self.max_size] * 0

    #isEmpty : function checks that given array is empty or not by using rare and front variables.
    def isEmpty(self):
        if (self.front == -1):
            return True
        else:
            return False
    
    #isFull : function checks that given array is full or not by using rare variable.
    def isFull(self):
        if (self.rear == self.max_size - 1 and self.front == 0) or (self.front == self.rear + 1):
            return True
        else:
            return False
    
    #enqueue : If the queue is not full, this function adds an element to the queue, else it prints “OverFlow”.
    def enqueue(self, value):
        if self.isFull() == True:
            print("Queue is OverFlow...So you can't add.")
            return
        else:
            #If queue is empty, increament front by 1.
            if self.isEmpty() == True:
                self.front = 0
            self.rear = (self.rear + 1) % self.max_size
            self.arr.append(value)

            print("Element {0} inserted successfully.".format(value))
            print()

    #dequeue : If the queue is not empty, this function removes the element from the queue, else it prints “UnderFlow”.
    def dequeue(self):
        if self.isEmpty() == True:
            print("Queue is UnderFlow...So you can't remove.")
            return 
        else:
            if self.rear == self.front:
                self.rear = self.front = -1
            else:
                self.front = (self.front + 1) % self.max_size
            no = self.arr.pop(0)
            print("Removed element : {0} \nElement removed successfully.".format(no))
            print()

#main() function.
def main():

    #Creating the object of Queue class.
    qobj = circularQueue()

    print("\n********** Queue Data Structure **********\n")

    #Inserting values into queue.
    qobj.enqueue(10)
    qobj.enqueue(20)
    qobj.enqueue(30)
    qobj.enqueue(40)
    qobj.enqueue(50)

    print("Queue after inserting 5 elements : ", qobj.arr)
    print()

    #Removing values from queue.
    qobj.dequeue()
    qobj.dequeue()
    qobj.dequeue()
    qobj.dequeue()
    qobj.dequeue()

    print("Queue after removing all elements : ", qobj.arr)
    print()

    print("Trying to insert elements into queue of capacity 5...")
    qobj.enqueue(60)
    qobj.enqueue(70)
    qobj.enqueue(80)
    qobj.enqueue(90)
    qobj.enqueue(100)

    print("Queue after inserting all elements: ", qobj.arr)
    print()

    #Removing and inserting new values.
    qobj.dequeue()
    qobj.enqueue(110)

    qobj.dequeue()
    qobj.enqueue(120)

    print("Final Queue: ", qobj.arr)


# It's as if the interpreter inserts this at the top of your module when run as the main program.
if __name__ == "__main__":
    main()