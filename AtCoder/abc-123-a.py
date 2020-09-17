mn, mx = float('inf'), -float('inf')
for i in range(5):
    a = int(input())
    mn = min(mn, a)
    mx = max(mx, a)
k = int(input())
if mx - mn > k:
    print(":(")
else:
    print("Yay!")