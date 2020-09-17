class xyz:
    global c
    def __init__(self):
        c+=1
        print("xyz init")
    def fun1(self):
        global c
        c+=1
        print("xyz.fun1")
class demo:
    def check(self,c):
        print(c)
class child(xyz, demo):
    def __init__(self):
        global c
        c+=1
        print("child init")
        super().__init__()
    def fun1(self):
        global c
        c+=1
        print("child.fun1")
c = 0
obj = child()
obj.check(c)