import collections, math
def solve():
    n = int(input())
    l = [0 for x in range(n)]
    for i in range(n):
        l[i] = int(input())
    m = int(input())
    c = [0 for x in range(n)]
    for i in range(n):
        c[i] = int(input())
    mp = collections.defaultdict(int)
    for i in range(n):
        mp[i] = collections.defaultdict(int)
        mp[i][l[i]] = c[i]
    # print(mp)
    for i in range(1, n):
        len = l[i];
        cost = c[i];
        for j in range(i):
            for key in mp[j].keys():
                g = math.gcd(len, key);
                comp = mp[i][g] if g in mp[i] else float('inf')
                mp[i][g] = min(mp[j][key] + cost, comp)
    ans = float('inf')
    for i in range(n):
        ans = min(ans, mp[i][1] if 1 in mp[i] else float('inf'));
    print(ans if ans != float('inf') else -1)
solve()