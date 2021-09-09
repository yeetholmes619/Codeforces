import math
t = int(input())
for i in range(t):
        n,k = map(int,input().split())
        if(k == 0):
                print(1)
                continue
        if(n%2 == 0):
                w = math.pow(2,n-1)
                w %= 1e9 + 7
                print(k*w)
        else:
                temp = math.pow(2,n-1)
                w = temp + 1
                l = temp -1
                ans = 0
                for i in range(k):
                        ans += ((math.pow(w,k-i)%(1e9 + 7))*(math.pow(l,i)%(1e9+7)))%(1e9+7)
                        ans %= 1e9 + 7
                print(ans)

