class Stack:
    def __init__(self):             #Constructor creates a list
        self.stack = list()

    def push(self,data):            #Adding elements to stack
        if data not in self.stack:  #Checking to avoid duplicate entries
            self.stack.append(data)
            return True
        return False

    def pop(self):                  #Removing last element from the stack
        if len(self.stack)<=0:
            return ("Stack Empty!")
        return self.stack.pop()
        
    def size(self):                 #Getting the size of the stack
        return len(self.stack)


my_stack = Stack()

print(my_stack.push(5)) #prints True
print(my_stack.push(6)) #prints True
print(my_stack.push(9)) #prints True
print(my_stack.push(5)) #prints False since 5 is there
print(my_stack.push(3)) #prints True
print(my_stack.size())  #prints 4 
print(my_stack.pop())   #prints 3
print(my_stack.pop())   #prints 9
print(my_stack.pop())   #prints 6
print(my_stack.pop())   #prints 5
print(my_stack.size())  #prints 0
print(my_stack.pop())   #prints Stack Empty!
