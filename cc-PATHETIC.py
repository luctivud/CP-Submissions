# '''     J A I ~ S H R E E ~ R A M     '''

# # Title: cc-PATHETIC.py
# # created on: 19-07-2020 at 22:24:35
# # Creator & Template : Udit Gupta "@luctivud"
# # https://github.com/luctivud
# # https://www.linkedin.com/in/udit-gupta-1b7863135/


# import math; from collections import *
# import sys; from functools import reduce
# from itertools import groupby

# # sys.setrecursionlimit(10**6)

# def get_ints(): return map(int, input().strip().split())
# def get_list(): return list(get_ints())
# def get_string(): return list(input().strip().split())
# def printxsp(*args): return print(*args, end="")
# def printsp(*args): return print(*args, end=" ")


# DIRECTIONS = [[0, 1], [0, -1], [1, 0], [1, -1]] #up, down, right, left
# NEIGHBOURS = [(i, j) for i in range(-1, 2) for j in range(-1, 2) if (i!=0 or j!=0)]


# OrdUnicode_a = ord('a'); OrdUnicode_A = ord('A')
# CAPS_ALPHABETS = {chr(i+OrdUnicode_A) : i for i in range(26)}
# SMOL_ALPHABETS = {chr(i+OrdUnicode_a) : i for i in range(26)}


# MOD_JOHAN = int(1e9)+7; MOD_LIGHT = 998244353; INFINITY = float('inf')
# MAXN_EYEPATCH = int(1e5)+1; MAXN_FULLMETAL = 501

# # Custom input output is now piped through terminal commands.


# def xlcm(a, b):
#     return (a*b)//math.gcd(a, b)

# prime = [i for i in range(101)]
# for i in range(2, 101):
#     if prime[i] == i:
#         for j in range(2*i, 101, i):
#             prime[j] = 1
# prime[4] = 2
# # print(prime)

# mylist = [2, 2]
# for i in range(3, 101):
#     if prime[i] == i:
#         mylist.append(i)
# sz = len(mylist)
        
# def bfs(s):
#     queue = deque()
#     visited = set()
#     visited.add(s)
#     queue.append((s, 1))
#     while len(queue):
#         node, dep = (queue.popleft())
#         dep += 1
#         for ngh in edges[node]:
#             if ngh not in visited:
#                 visited.add(ngh)
#                 # babe =  xlcm(dep, ans[ngh])
#                 # print(babe, ans[ngh], dep)
#                 # if gcd
#                 # ans[ngh] = babe
#                 # ans[ngh].append(dep)
#                 ans[ngh] = max(ans[ngh], dep)
#                 queue.append((ngh, dep))



# for _testcases_ in range(int(input())): 
#     edges = defaultdict(list)
#     n = int(input())
#     for _ in range(n-1):
#         a, b = get_ints()
#         edges[a].append(b)
#         edges[b].append(a)
#     # print(edges)
#     ans = [1] * (n+1)
#     # ans = defaultdict(list)
#     for i in range(1, n+1):
#         bfs(i)
#     print(ans)


#     # assert(nairobi[-1] < 1e18)


# '''
# THE LOGIC AND APPROACH IS MINE ( UDIT GUPTA )
# Link may be copy-pasted here, otherwise.
# '''



'''     J A I ~ S H R E E ~ R A M     '''

# Title: cc-PATHETIC.py
# created on: 19-07-2020 at 22:24:35
# Creator & Template : Udit Gupta "@luctivud"
# https://github.com/luctivud
# https://www.linkedin.com/in/udit-gupta-1b7863135/


import math; from collections import *
import sys; from functools import reduce
from itertools import groupby

# sys.setrecursionlimit(10**6)

def get_ints(): return map(int, input().strip().split())
def get_list(): return list(get_ints())
def get_string(): return list(input().strip().split())
def printxsp(*args): return print(*args, end="")
def printsp(*args): return print(*args, end=" ")


DIRECTIONS = [[0, 1], [0, -1], [1, 0], [1, -1]] #up, down, right, left
NEIGHBOURS = [(i, j) for i in range(-1, 2) for j in range(-1, 2) if (i!=0 or j!=0)]


OrdUnicode_a = ord('a'); OrdUnicode_A = ord('A')
CAPS_ALPHABETS = {chr(i+OrdUnicode_A) : i for i in range(26)}
SMOL_ALPHABETS = {chr(i+OrdUnicode_a) : i for i in range(26)}


MOD_JOHAN = int(1e9)+7; MOD_LIGHT = 998244353; INFINITY = float('inf')
MAXN_EYEPATCH = int(1e5)+1; MAXN_FULLMETAL = 501

# Custom input output is now piped through terminal commands.


def xlcm(a, b):
    return (a*b)//math.gcd(a, b)

prime = [i for i in range(101)]
for i in range(2, 101):
    if prime[i] == i:
        for j in range(2*i, 101, i):
            prime[j] = 1
prime[4] = 2
# print(prime)
allprimes = [i for i in range(2, 100) if prime[i] == i]
# print(len(allprimes))
p1 = 1
p2 = 1
ind  = 0
while ind < 25 and p1 * allprimes[ind] < 1e18:
    p1 *= allprimes[ind]
    ind += 1
while ind < 25 and p2 * allprimes[ind] < 1e18:
    p2 *= allprimes[ind]
    ind += 1
# print(ind)
print(1e18/p1, 1e18/p2)
# assert ind == 25
while ind == 24:
    gizmo1 = 1e18/p1
    gizmo2 = 1e18/p2
    print(gizmo1, gizmo2)
    if gizmo1 < gizmo2:
        for i in allprimes:
            if i < gizmo2:
                jeje = i
            else:
                break
        if jeje == allprimes[24]:
            ind += 1
        p2 *= jeje
        p1 //= jeje
    else:
        for i in allprimes:
            if i < gizmo1:
                jeje = i
            else:
                break
        if jeje == allprimes[24]:
            ind += 1
        p1 *= jeje
        p2 //= jeje
    print(jeje)
    
assert ind == 25
assert p1 < 1e18
assert p2 < 1e18



assign = [p1, p2]

def bfs(s):
    queue = deque()
    visited = set()
    visited.add(s)
    queue.append((s, 1))
    ans[1] = assign[1]
    while len(queue):
        node, dep = (queue.popleft())
        dep += 1
        for ngh in edges[node]:
            if ngh not in visited:
                visited.add(ngh)
                queue.append((ngh, dep))
                ans[ngh] = assign[dep&1]


                # babe =  xlcm(dep, ans[ngh])
                # # print(babe, ans[ngh], dep)
                # # if gcd
                # ans[ngh] = babe
                # # ans[ngh].append(dep)



for _testcases_ in range(int(input())): 
    edges = defaultdict(list)
    n = int(input())
    for _ in range(n-1):
        a, b = get_ints()
        edges[a].append(b)
        edges[b].append(a)
    # print(edges)
    ans = [1] * (n+1)
    bfs(1)
    print(*ans[1:])


    # # ans = defaultdict(list)
    # for i in range(1, n+1):
    #     bfs(i)
    # heheh = ans[1]
    # for i in range(2, n+1):
    #     heheh = math.gcd(heheh, ans[i])
    # for i in range(1, n+1):
    #     ans[i] //= heheh
    # print(*ans[1:])
    # # for i in range(1, n+1):
    # #     if ans[i] % 2:
    # #         print(i)


    # # assert(nairobi[-1] < 1e18)


'''
THE LOGIC AND APPROACH IS MINE ( UDIT GUPTA )
Link may be copy-pasted here, otherwise.
'''
