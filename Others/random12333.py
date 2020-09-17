# #~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~#
# # Udit Gupta @luctivud  神 | LIGHT | GREED | CIPHER | XAYN
# #~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~#
#                 ##     ##   ######   # #  ######
#                 ##     ##   ##  ##   ###    ##
#                 ##     ##   ##   #   # #    ##
#                 ###### ##   ######   # #    ##
# #~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~#
# #                   | WORSHIPPER OF GREED | 
# #~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~#
# for _testcases_ in range(int(input())):
#     n = int(input())
#     li =  list (map(int, input().split()))
#     ans = 1
#     ali = [1]*n
#     for i in range(n):
#         if i == 0:
#             if li[n-1] == li[1] and li[i] != li[n-1] and li[i]!=li[1]:
#                 ali[0] = 1; ali[1] = 2; ali[n-1]=2;
#                 ans = 2
#             elif li[n-1] != li[1] and li[i] != li[n-1] and li[i]!=li[1]:
#                 ali[0]=1; ali[1]=2; ali[n-1]=3;
#                 ans = 3
#             else:
#                 ali[0]=1; ali[1]=1; ali[n-1]=1;
#         else:
#             if li[i-1] == li[(i+1)%n] and li[i] != li[i-1] and li[i]!=li[(i+1)%n]:
#                 ali[(i+1)%n] = ali[i-1]
#                 if ali[i-1] == 1:
#                     ali[i] = 2
#                 else:
#                     ali[i] = 1
#                 ans = 2
#             elif li[i-1] != li[(i+1)%n] and li[i] != li[i-1] and li[i]!=li[(i+1)%n]:
#                 se = list(1, 2, 3)
#                 se.remove(ali[(i-1)%n]);
#                 ali[i] = se[0]
#                 ali[(i+1)%n] = se[1]
#                 ans = 3
#             else:
#                 ali[(i+1)%n] = ali[i-1]; ali[i] = ali[i-1];
                
#     print(ans)
#     for el in ali:
#         print(el, end=" ")
#     print()

