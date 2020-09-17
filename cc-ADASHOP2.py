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
for __ in range(int(input())):
    r0,c0 = map(int, input().split())
    allMoves = [(1,7),(2,8),(8,2),(7,1),(1,7),(2,6),(1,5),(4,8),(8,4),(5,1),(1,5),(2,4),(1,3),(6,8),(8,6),(3,1),(1,3),(2,2),(1,1),(8,8),(4,4)]
    sz = len(allMoves)
    startTupleList = [ (1,1),(3,1),(5,1),(7,1),(1,7),(1,5),(1,3) ]
    startTuple = startTupleList[(r0-c0)//2]
    startIndex = allMoves.index(startTuple)
    # print(startTuple, startIndex)
    print(sz)
    for i in range(sz):
        (a, b) = allMoves[(startIndex+i)%sz]
        print(a,b)