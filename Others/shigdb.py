n = bin(n)[2:]
n = ('0' * (32 - len(n))) + n[::-1];
ok = True
if n[-1] == '1':
    ok = False
    n = n.replace('1', '$')
    n = n.replace('0', '1')
    n = n.replace('$', '0')
n = n[1:]
n = int(n[::-1], 2)
if ok:
    return n
else:
    return -n
