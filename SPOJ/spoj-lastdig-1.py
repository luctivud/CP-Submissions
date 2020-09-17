# import sys
# sys.stdin=open("input.txt","r");sys.stdout=open("output.txt","w")
for _ in range(int(input())):
    a, b = map(int, input().split())
    if b == 0:
        print(1)
    else:
        if b % 4 == 0:
            b1 = 4
        else:
            b1 = b % 4
        print(((a%10)**(b1)) % 10)
    # try:
    #     assert (((a%10)**(b1)) % 10) == (a ** b) % 10
    #     print('True')
    # except:
    #     print('False')
'''
>>> COMMENT THE STDIN!! CHANGE ONLINE JUDGE !!
THE LOGIC AND APPROACH IS MINE @luctivud ( UDIT GUPTA )
Link may be copy-pasted here if it's taken from other source.
DO NOT PLAGIARISE.
>>> COMMENT THE STDIN!! CHANGE ONLINE JUDGE !!
'''