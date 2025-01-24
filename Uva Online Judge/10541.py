fact=200*list({1})
fact[0]=1
for i in range(1,200):
    fact[i]=fact[i-1]*i
T=int(input())
for i in range(T):
    L=list(map(int,input().split()))
    blank=L[0]
    k=len(L)
    for j in range (2,k):
        blank-=L[j]
    blank-=L[1]
    blank+=1
    #print(blank)
    if(blank<0):
        print(0)
    else:
        totespacios=2*L[1]+blank-1
        res=fact[blank+L[1]]//(fact[blank]*fact[L[1]])
        print(res)
