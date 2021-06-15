import collections
b = input()
a = set(input())
ca = cb = 0

for i in b:
  if i in a:
    ca += 1
  else:
    cb += 1
print(ca, cb)
# assert(ca + cb == len)
  
