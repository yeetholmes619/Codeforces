cred = 33
ans = 8.06
while (True):
        k,i = map(int,input().split())
        ans = (ans*cred + k*i)/(cred+k)
        cred += k;
        print(ans)
