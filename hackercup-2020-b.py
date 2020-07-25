T = int(input())
for _Test_ in range(1, T+1):
    print("Case #{}:".format(_Test_), end=" ")
    n = int(input())
    s = input()
    a = s.count('A')
    b = s.count('B')
    if abs(a-b) == 1:
        print('Y')
    else:
        print('N')