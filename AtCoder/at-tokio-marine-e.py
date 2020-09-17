class Solution:
    def minDays(self, a: List[int], m: int, k: int) -> int:
        n = len(a)
        if m * k > n:
            return -1
        prefix_sum=[0]*n 
        s=[0] 
        for i in range(1,n): 
            while (len(s) > 0 and a[s[-1]] < a[i]): 
                prefix_sum[s[-1]] = i - 1
                del s[-1] 
            s.append(i) 
            
        while (len(s) > 0): 
            prefix_sum[s[-1]] = n - 1
            del s[-1] 
        j = 0
        li = []
        for i in range(n - k + 1):
            while (j < i or prefix_sum[j] < i + k - 1): 
                j += 1
            li.append([a[j], i])
        li.sort(key = lambda x: (x[0], x[1]))
        # print(li)
        ans = []
        se = set()
        for i in range(len(li)):
            flag = True
            se2 = set()
            for j in range(li[i][1], li[i][1]+k):
                if j in se:
                    flag= False
                    break
                else:
                    se2.add(j)
            if flag :
                se = se.union(se2)
                ans.append(li[i][0])
            if len(ans)==m:
                break
            # print(se)
        if len(ans)<m:
            return -1
        return max(ans)