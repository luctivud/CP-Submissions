def Solution(S, C):
    stack = []
    n = len(S)
    ans = 0
    for i in range(n):
        if len(stack) and stack[-1][0] == S[i]:
            a, b = min(C[i], stack[-1][1]), max(C[i], stack[-1][1])
            stack.pop()
            ans += a
            stack.append((S[i], b))
        else:
            stack.append((S[i], C[i]))
    return ans

print(Solution("aabbcc", [1, 2, 1, 2, 1, 2]))
print(Solution("abccbd", [i for i in range(6)]))