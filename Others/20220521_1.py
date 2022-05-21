#   J A I  S H R E E  R A M   #


import math, sys, collections, functools, time, itertools;

# sys.setrecursionlimit(10**6)


def Read_Ints()     : return map(int, input().strip().split())
def Read_Array()    : return list(Read_Ints())
def Read_Strings()  : return list(input().strip().split())
def printxsp(*args) : return print(*args, end="")
def printsp(*args)  : return print(*args, end=" ")



d4i = [-1, +0, +1, +0]; d8i = [-1, -1, +0, +1, +1, +1, +0, -1]; 
d4j = [+0, +1, +0, -1]; d8j = [+0, +1, +1, +1, +0, -1, -1, -1];


# >>>>>>--->>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>





def solveEachTest(_TestCase):
    # printsp("Case #{}: ".format(_TestCase)) 
    b = Read_Array()
    g = Read_Array()
    n = len(b)
    sum_b = sum(b)
    sum_g = sum(g)
    total_sum = sum_g + sum_b
    res_b = []
    res_g = []
    for i in range(n):
        rt = sum_b
        ct = b[i] + g[i]
        res = round((rt * ct) / total_sum, 2)
        res_b.append(res)
        rt = sum_g
        res = round((rt * ct) / total_sum, 2)
        res_g.append(res)
    print(res_b)
    print(res_g)

    table = []
    table.append(["fo", "fe", "fo-fe", "(fo-fe)2", "(fo-fe)2/fe"])
    for i in range(n):
        fo = b[i]
        fe = res_b[i]
        diff = round(fo - fe, 2)
        diff2 = round(diff * diff, 2)
        mean = round(diff2 / fe, 2)
        res = [fo, fe, diff, diff2, mean]
        table.append(res)
    table.append([])
    for i in range(n):
        fo = g[i]
        fe = res_g[i]
        diff = round(fo - fe, 2)
        diff2 = round(diff * diff, 2)
        mean = round(diff2 / fe, 2)
        res = [fo, fe, diff, diff2, mean]
        table.append(res)
        
    for i in table:
        s = " ".join([str(j).ljust(10) for j in i])
        print(s)




_T0T4 = 1;
# _T0T4 = int(input()) 
for _TestCase in range(1, _T0T4 + 1): 
    solveEachTest(_TestCase)


# Udit "luctivud" Gupta 
# linkedin :  https://www.linkedin.com/in/udit-gupta-1b7863135/

