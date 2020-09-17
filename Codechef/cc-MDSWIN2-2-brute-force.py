#~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~#
# Udit Gupta @luctivud  神 | LIGHT | GREED | CIPHER | XAYN
#~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~#
                ##     ##   ######   # #  ######
                ##     ##   ##  ##   ###    ##
                ##     ##   ##   #   # #    ##
                ###### ##   ######   # #    ##
#~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~#
#                   | WORSHIPPER OF GREED | 
#~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~#
# ##########################################################
N = 100001
factorialNumInverse = [None] * (N + 1) 
naturalNumInverse = [None] * (N + 1) 
fact = [None] * (N + 1) 
def InverseofNumber(p): 
    naturalNumInverse[0] = naturalNumInverse[1] = 1
    for i in range(2, N + 1, 1): 
        naturalNumInverse[i] = (naturalNumInverse[p % i] * (p - int(p / i)) % p) 

def InverseofFactorial(p): 
    factorialNumInverse[0] = factorialNumInverse[1] = 1
    for i in range(2, N + 1, 1): 
        factorialNumInverse[i] = (naturalNumInverse[i] * factorialNumInverse[i - 1]) % p 
  
def factorial(p): 
    fact[0] = 1
    for i in range(1, N + 1): 
        fact[i] = (fact[i - 1] * i) % p 
  
def Binomial(N, R, p): 
    ans = ((fact[N] * factorialNumInverse[R])% p * factorialNumInverse[N - R])% p 
    return ans 
# ##########################################################
for _testcases_ in range(int(input())):
    p = 998244353
    InverseofNumber(p) 
    InverseofFactorial(p) 
    factorial(p) 
    n = int(input())
    li = list(map(int, input().split()))
    # allNums = {}
    # for i in range(len(li)):
    #     try:
    #         allNums[li[i]].append(i)
    #     except:
    #         allNums[li[i]] = i
    # ####### can try dict of range-list HERE for full #######################
    for _query_ in range(int(input())):
        d = {};  countNumbers = []; pairs = 0; ans=0;
        l, r = map(int, input().split())
        for i in range(l-1, r):
            try:
                d[li[i]] += 1
            except:
                d[li[i]] = 1
        for k, v in d.items():
            countNumbers.append(v)
        # print(countNumbers)
        for i in countNumbers:
            pairs=pairs^i
        if pairs != 0:
            for i in countNumbers:
                upperbound = i
                lowerbound = pairs^i
                if upperbound - lowerbound > 0:
                    ans += Binomial(upperbound, lowerbound, p)
                    ans = ans % 998244353
        print(ans % 998244353)