#~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~#
#   '          .       ,     神 | 光      .     '        .      , #
#     .      '        Udit Gupta @luctivud         ,              #
#  ,    '   ELDIOS | LIGHT | GREED | CIPHER | XAYN | KIRA '    .  #
#~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~#
                ##     ##   ######   # #  ######
                ##     ##   ##  ##   ###    ##
                ##     ##   ##   #   # #    ##
                ###### ##   ######   # #    ##
#~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~#
#~~~~~~~~~~~~~~~~~~~~| WORSHIPPER OF GREED |~~~~~~~~~~~~~~~~~~~~~~~#
#~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~#
import sys
import math as mt
# sys.setrecursionlimit(10**6)
def printsp(*args): return print(*args, end=" ")
def printchk(*args): return print(*args, end="tst, ")
def get_ints(): return map(int, sys.stdin.readline().strip().split())
def get_array(): return list(map(int, sys.stdin.readline().strip().split()))
def input(): return sys.stdin.readline().strip()
MOD = int(1e9+7); BABYMOD = 1 ;MODD = 998244353
#########################################################################
dpow = [-1]*10000
def dpower(x, y):
    # print(x,y)
    if y==0: return 1
    try:
        if dpow[y]!=-1: return dpow[y]
    except:pass
    temp = dpower(x, y//2)
    if (y%2 == 0):
        try:
            dpow[y]=temp*temp
        except:pass
        return temp*temp;
    else:
        try: dpow[y]=x*temp*temp
        except:pass
        return x*temp*temp; 

def performOperation(val1, val2, opr):
    if val1==0: val1=[1,1,1,1]
    if val2==0: val2=[1,1,1,1]
    ans = [0,0,0,0]
    # if val1==ans and val2==ans:
    #     if opr=='&':
    #         ans = [9, 1, 3, 3]
    #     elif opr=='|':
    #         ans = [1, 9, 3, 3]
    #     elif opr=='^':
    #         ans = [4, 4, 4, 4]
    # elif val1==ans or val2==ans:
    #     val=[]
    #     for i in range(4):
    #         val.append(val1[i]+val2[i])
    #     if opr=='&':
    #         ans[0] = ((4*val[0])+val[1]+(4*val[2]))
    #         ans[1] = (1*val[1])
    #         ans[2] = val[1]+(2*val[2])  
    #         ans[3] = ans[2]
    #     elif opr=='|':
    #         ans[0] = (1*val[0])
    #         ans[1] = (((4*val[1]))+val[0]+((4*val[2])))
    #         ans[2] = val[1]+(2*val[2])
    #         ans[3] = ans[2]
    #     elif opr=='^':
    #         ans[0] = sum(val)
    #         ans[1] = ans[0]
    #         ans[2] = sum(val)
    #         ans[3] = ans[2]
    # else:
    if opr=='&':
        ans[0] = ((val1[0]*sum(val2)))+((val1[1]*val2[0]))+((val1[2]*(val2[3]+val2[0])))+((val1[3]*(val2[0]+val2[2])))
        ans[1] = (val2[1]*val1[1])
        ans[2] = (val1[2]*(val2[1]+val2[2]))+(val1[1]*val2[2])
        ans[3] = ans[2]
    elif opr=='|':
        ans[0] = (val1[0]*val2[0])
        ans[1] = ((val1[1]*sum(val2)))+((val1[0]*val2[1]))+((val1[2]*(val2[3]+val2[1])))+((val1[3]*(val2[1]+val2[2])))
        ans[2] = (val1[0]*val2[2]) + (val1[2]*(val2[0]+val2[2]))
        ans[3] = ans[2]
    elif opr=='^':
        ans[0] = ((val1[0]*val2[0]))+((val1[1]*val2[1]))+((val1[2]*val2[2]))+((val1[3]*val2[3]))
        ans[1] = ((val1[1]*val2[0]))+((val1[0]*val2[1]))+((val1[3]*val2[2]))+((val1[2]*val2[3]))
        ans[2] = ((val1[0]*val2[2]))+((val1[1]*val2[3]))+((val1[2]*val2[0]))+((val1[3]*val2[1]))
        ans[3] = ans[2]
    # ans[2] = (int(mt.sqrt(ans[0])))*(int(mt.sqrt(ans[1])))
    # try:
    # except: pass
    # ans[3] = ans[2]
    # ans[2] = (pow(4, ans[4])-ans[0]-ans[1])//2
    # ans[3] = ans[2]
    return ans 
# /////////////////////////////////////////////////
for _testcases_ in range(int(input())):
    s=input()
    values=[]
    par=[]
    q=0
    for i in s:
        if i=='(':
            pass
        elif i==')':
            val1=values.pop()
            val2=values.pop()
            opr=par.pop()
            a=performOperation(val1, val2, opr)
            # print(a)
            values.append(a)
        elif i=='#':
            values.append(0)
            q+=1
        else:
            par.append(i)
    if values[0]==0:
        values[0]=[1,1,1,1]
    # values[0].pop()
    # print(values[0])
    q=dpower(4, q)
    q=pow(q, MODD-2, MODD)
    for i in values[0]:
        printsp((i *q)%MODD)
    print()
# /////////////////////////PROGRAM TO STAND WITH THE LOGIC/////////////////////
# a=1; A=0
# count=0; total=0
# li=[1,0,1,0]
# ansli1=[]
# for i in range(4):
# 	for j in range(4):
# 		# ansli1.append(li[i]^li[j])
# 		for k in range(4):
# 			# ansli1.append((li[i]&li[j])|(li[k]))
# 			for l in range(4):
# 				ansli1.append((li[i]|li[j])^(li[k]|li[l]))
# 				# ansli1.append(((li[i]&li[j])&li[k])^li[l])
# 				# for m in range(4):
# 				# 	ansli1.append(((li[i]&li[j])|li[m])|(li[k]&li[l]))
# # a=0;A=1;
# li=[1,0,0,1]
# ansli2=[]
# for i in range(4):
# 	for j in range(4):
# 		# ansli2.append(li[i]^li[j])
# 		for k in range(4):
# 			# ansli2.append((li[i]&li[j])|(li[k]))
# 			for l in range(4):
# 				ansli2.append((li[i]|li[j])^(li[k]|li[l]))
# 				# ansli2.append(((li[i]&li[j])&li[k])^li[l])
# 				# for m in range(4):
# 				# 	ansli2.append(((li[i]&li[j])|li[m])|(li[k]&li[l]))
# ans=[0,0,0,0]
# for i in range(len(ansli1)):
# 	if ansli1[i]==0 and ansli2[i]==0:
# 		ans[0]+=1
# 	elif ansli1[i]==1 and ansli2[i]==1:
# 		ans[1]+=1
# 	elif ansli1[i]==0 and ansli2[i]==1:
# 		ans[2]+=1
# 	elif ansli1[i]==1 and ansli2[i]==0:
# 		ans[3]+=1
# print(ans)
# # print(ansli1)
# # print(ansli2)
# # print(ansli1)
# # print(ansli2)
# # # ???????????????????????????????????????????????????????????????????
# # s=input()
# # par=[]
# # op=[]
# # for i in s:
# # 	if i=='(':
# # 		par.append(i)
# # 	elif i==')':
# # 		par.pop()
# # 		print(op.pop(), end=" ")
# # 	elif i!='#':
# # 		op.append(i)
# # for i in op:
# # 	print(i, end=" ")
# # # ////////////////////////////////////////////////////////////////
'''
6
(((#&#)|(#&#))^#)
(((#&#)^(#^#))&(#|#))
#
((#^#)&(#&#))
(((#&#)^(#&#))&#)
((#&#)&(#&#))
'''