s = input()
print("YES" if (str(sum([1 if i in '47' else 0 for i in s])) in '47') else "NO")