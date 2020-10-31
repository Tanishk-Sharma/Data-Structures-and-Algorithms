class Queue:
  def __init__(self):                       #Constructor creates a list
      self.queue = list()

  def enqueue(self,data):                   #Adding elements to queue
      if data not in self.queue:              #Checking to avoid duplicate entry (not mandatory)
          self.queue.insert(0,data)
          return True
      return False

  def dequeue(self):                        #Removing the last element from the queue
      if len(self.queue)>0:
          return self.queue.pop()
      return ("Queue Empty!")

  def size(self):                           #Getting the size of the queue
      return len(self.queue)

  def printQueue(self):                     #printing the elements of the queue
      return self.queue


my_queue = Queue()

print(my_queue.enqueue(5)) #prints True
print(my_queue.enqueue(6)) #prints True
print(my_queue.enqueue(9)) #prints True
print(my_queue.enqueue(5)) #prints False
print(my_queue.enqueue(3)) #prints True
print(my_queue.size())     #prints 4
print(my_queue.dequeue())  #prints 5
print(my_queue.dequeue())  #prints 6
print(my_queue.dequeue())  #prints 9
print(my_queue.dequeue())  #prints 3
print(my_queue.size())     #prints 0
print(my_queue.dequeue())  #prints Queue Empty!
