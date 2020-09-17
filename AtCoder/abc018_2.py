s = input()
n = int(input())

for i in range(n):
    l, r = map(int, input().split())
    l -= 1
    new = ''
    if l > 0:
        new += s[:l]
    new += s[l:r][::-1]
    if r < len(s):
        new += s[r:]
    s = new
print(s)