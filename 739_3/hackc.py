for _ in range(int(input())):
    k=int(input())
    c=1;i=1
    while(c<k):
        x=c+i*2-1
        if x>k:
            break
        c=x
        i+=1
    if k<=(c+i-1):
        print(k-c+1,i)
    else:
        x=c+i-1
        print(i,i-(k-x))