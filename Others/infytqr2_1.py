from itertools import groupby


def convertToBase(x, base):
    if x == 0:
        return "0"
    digits = []
    while x:
        digits.append(str(x % base))
        x //= base
    digits.reverse()
    return ''.join(digits)


num = int(input())
base = int(input())
g = groupby(convertToBase(num, base))
ans = -1
for ke, va in g:
    if ke == '0':
        ans = max(ans, len(list(va)))
print(ans)