#   J A I  S H R E E  R A M   #


import math, sys, collections, functools, time, itertools;

# sys.setrecursionlimit(10**6)


def Read_Ints()     : return map(int, input().strip().split())
def Read_Array()    : return list(Read_Ints())
def Read_Strings()  : return list(input().strip().split())
def printxsp(*args) : return print(*args, end="")
def printsp(*args)  : return print(*args, end=" ")

input = sys.stdin.readline

d4i = [-1, +0, +1, +0]; d8i = [-1, -1, +0, +1, +1, +1, +0, -1]; 
d4j = [+0, +1, +0, -1]; d8j = [+0, +1, +1, +1, +0, -1, -1, -1];


# >>>>>>--->>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>





def solveEachTest(_TestCase):
    # printsp("Case #{}: ".format(_TestCase)) 
    NewRandom = open("Zoutput.txt", "r")
    MarkGood = open("ZGood.txt", "r")
    res = []

    NewRandomLs = list(NewRandom)
    MarkGoodLs = list(MarkGood)
    MarkGood.close()
    NewRandom.close()
    # print(len(MarkGoodLs))
    # print(len(NewRandomLs))
    res = []
    # print(len(res))
    # print(MarkGoodLs[5])
    # print(list(NewRandom.strip('\n')))
    ln = 0
    chngs = 0
    while (True):
        try:
            lineRandomLs = NewRandomLs[ln].split()
            lineGoodLs = MarkGoodLs[ln].split()
            if float(lineRandomLs[2].strip('\n')) < float(lineGoodLs[2].strip('\n')):
                # print(float(lineRandomLs[2].strip('\n')), float(lineGoodLs[2].strip('\n')))
                # res[ln] = (lineRandomLs).copy()
                res.append(lineRandomLs)
                # print(ln, res[ln])
                chngs += 1
            else:
                # res[ln] = (lineGoodLs).copy()
                res.append(lineGoodLs)
            ln += 1
        except:
            break
    # print(res)
    GoodNewFile = open("ZGood.txt", "w")
    # GoodNewFile.write(*res)
    for i in res:
        # print(" ".join(i))
        # print()
        GoodNewFile.write(" ".join(i))
        GoodNewFile.write("\n")
    GoodNewFile.write("ok")
    GoodNewFile.close()
    print(ln, chngs)




_T0T4 = 1;
# _T0T4 = int(input()) 
for _TestCase in range(1, _T0T4 + 1): 
    solveEachTest(_TestCase)


# Udit "luctivud" Gupta math
# linkedin :  https://www.linkedin.com/in/udit-gupta-1b7863135/

