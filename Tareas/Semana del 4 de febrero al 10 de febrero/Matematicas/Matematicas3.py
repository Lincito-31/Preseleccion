for i in range(1000):
    x=pow((pow(10,i)-1)//9,2)
    sum=0
    while(x>0):
        sum+=x%10
        x//=10
    if(sum!=(int)((i//9)*81+pow(i%9,2))):
        print(i)