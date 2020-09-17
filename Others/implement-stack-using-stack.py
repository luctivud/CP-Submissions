class Stack:
    def __init__(self):
        self.items = []
 
    def is_empty(self):
        return self.items == []
 
    def push(self, data):
        self.items.append(data)
 
    def pop(self):
        return self.items.pop()

    def display(self):
        if self.items == []:
            return "Empty Stack"
        return self.items

s = Stack()
while True:
    try:
        print('1 push\n2 pop\n3 display\n0 quit')
        n = int(input('Enter your choice: '))
        if n == 1:
            s.push(int(input('Enter the data to push- ')))
        elif n == 2:
            if s.is_empty():
                print('Stack is empty.')
            else:
                print('Popped value: ', s.pop())
        elif n == 3:
            print(s.display())
        else:
            print("Exit..")
            break
        print()
    except:
        print("Some Error occured, try again!\n")