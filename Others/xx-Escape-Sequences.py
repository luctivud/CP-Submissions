import typing 
Q: int = int(input())
sumOfTestCases = 0
for query in range(Q):
    N:int = int(input())
    S:str = input()
    assert(len(S) == N) #Check len
    i:int = 0
    while i < N:
        if S[i] != '\\':
            print(S[i], end = '')
            i += 1
        else:
            try:
                if S[i+1] == '\\' and S[i+2] == 'n':
                    print(S[i+1] + S[i+2], end = '')
                    i += 3
                elif S[i+1] == 'n':
                        print()
                        i += 2
                else:
                    print(S[i], end = "")
                    i += 1
            except:
                try:
                    if S[i+1] == 'n':
                        print()
                        i += 2
                    else:
                        print(S[i], end = '')
                        i += 1
                except:
                    print(S[i], end = '')
                    i += 1
    print()
    sumOfTestCases += N
assert(sumOfTestCases < 1e6)

    # this is the unpythonic way and can be implemented in any lang, and ofc it can be made shorter.
