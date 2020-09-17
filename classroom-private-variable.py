class Demo:
    def __init__(self):
        self.__P = 9
        self.A = 10
    def changeP(self, newValue):
        self.__P = newValue
    def getP(self):
        print(self.__P, self.A)
obj = Demo()
obj.getP()
obj.changeP(3)
obj.getP()