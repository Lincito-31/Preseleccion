t=1
MOD=1000000009
def bigmod(base,power):
  p=1
  while(power>0):
    if(power%2==1):
      p*=base
    base*=base
    power//=2
  return p
t=int(input())
while(t!=0):
    n,k=map(int,input().split())
    nums=list(map(int,input().split()))
    tot0=0
    for i in range(n):
        if(nums[i]==0):
            tot0+=1
    posi=True
    for i in range(n):
        if(nums[i]!=0):
            if(nums[n-1-i]==0 or nums[n-i-1]==nums[i]):
                nums[n-i-1]=nums[i]
            else:
                posi=False
                break
    if(posi):
        nue0=0
        for i in range(n):
            if(nums[i]==0):
                nue0+=1
        direc=bigmod(k,tot0)-(bigmod(k,nue0)-bigmod(k,(nue0+1)//2))//2
        direc%=MOD
        print(direc)
    else:
        print(bigmod(k,tot0))
    t-=1