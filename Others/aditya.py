# a = input()
# # a = int(a)
# print(a+"ab")

# a = "absjc"
# a = 5462892408204807397917391739240284028402840248
# print(a * 131853185383 * a * a * a * a * a * a)
# print(a+a)

# for i in range(7):
#     print()
#     if 1 == 1:
#         print()
# print()

'''

+
-
*
/ 5 / 2 = 2.5
// 5 // 2 = 2
% 
# print(divmod(117, 11))
# print(17 % 11)

= assignment
== compare
> , <

a b g 
((a * b) / g)

'''
import math



n, k = map(int, input().split())
ans = 0

for i in range(n):
    t = int(input())
    # print(t % k)
    if t % k == 0:
        ans = ans + 1

    print(math.gcd(t, k))

print(ans)



