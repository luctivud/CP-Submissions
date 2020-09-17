def performOperation(val1, val2, opr):
    ans = [0,0,0,0]
    if val1==ans and val2==ans:
        if opr=='&':
            ans = [9, 1, 3, 3]
        elif opr=='|':
            ans = [1, 9, 3, 3]
        elif opr=='^':
            ans = [4, 4, 4, 4]
    elif val1==ans or val2==ans:
        val=[]
        for i in range(4):
            val.append(val1[i]+val2[i])
        if opr=='&':
            ans[0] = 4*val[0]+val[1]+4*val[2]
            ans[1] = 1*val[1]
        elif opr=='|':
            ans[0] = 1*val[0]
            ans[1] = 4*val[1]+val[0]+4*val[2]
        elif opr=='^':
            ans[0] = sum(val)
            ans[1] = ans[0]
    else:
        if opr=='&':
            ans[0] = val1[0]*sum(val2)+val1[1]*val2[0]+val1[2]*(val2[3]+val2[0])+val1[3]*(val2[0]+val2[2])
            ans[1] = val2[1]*val1[1]
        elif opr=='|':
            ans[0] = val1[0]*val2[0]
            ans[1] = val1[1]*sum(val2)+val1[0]*val2[1]+val1[2]*(val2[3]+val2[1])+val1[3]*(val2[1]+val2[2])
        elif opr=='^':
            ans[0] = val1[0]*val2[0]+val1[1]*val2[1]+val1[2]*val2[2]+val1[3]*val2[3]
            ans[1] = val1[1]*val2[0]+val1[0]*val2[1]+val1[3]*val2[2]+val1[2]*val2[3]
    ans[2] = int(ans[0]**0.5)*int(ans[1]**0.5)
    ans[3] = ans[2]
    return ans
s=input()
values=[]
par=[]
for i in s:
    if i=='(':
        par.append(i)
    elif i==')':
        val1=values.pop()
        val2=values.pop()
        opr=par.pop()
        par.pop()
        values.append(performOperation(val1, val2, opr))
    elif i=='#':
        values.append([0,0,0,0])
    else:
        par.append(i)
    print(values, par)
for i in par:
    val1=values.pop()
    val2=values.pop()
    opr=par.pop()
    values.append(performOperation(val1, val2, opr))
print(values, "ans")
# par=[]
# op=[]
# for i in s:
# 	if i=='(':
# 		par.append(i)
# 	elif i==')':
# 		par.pop()
# 		print(op.pop(), end=" ")
# 	elif i!='#':
# 		op.append(i)
# for i in op:
# 	print(i, end=" ")