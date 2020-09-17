class Time:
    def __init__(self, hr, mn):
        self.hours = hr
        self.minutes = mn

    def displayMinute(self):
        print(self.hours*60+self.minutes, "minutes")

    def displayTime(self):
        print(self.hours,"hr:",self.minutes,"min")

    def addTime(self,obj1, obj2):
        minutes = obj1.minutes + obj2.minutes()
        hours = obj1.hours + obj2.hours + (minutes//60)
        minutes = (minutes%60)
        print(hours, minutes)

t1 = Time(1, 20)
t1.displayTime()
t1.displayMinute()
t2 = Time(3,5)
t2.displayTime()
t2.displayMinute()
Time.addTime(t1, t2)
t1.displayTime()