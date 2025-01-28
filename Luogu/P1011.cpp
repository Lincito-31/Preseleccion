#include <bits/stdc++.h>
using namespace std;
int n,a,m,x;
vector<pair<int,int>> fib(21);
vector<pair<int,int>> res(21);
pair<int,int> operator+(pair<int,int>x,pair<int,int>y){
    return {x.first+y.first,x.second+y.second};
}
int main(){
    fib[1]={1,0};
    fib[2]={0,1};
    scanf("%d%d%d%d",&a,&n,&m,&x);
    res[0]={0,0};
    res[1]=res[2]={1,0};
    for(int i=3;i<n;i++){
        res[i]=res[i-1]+fib[i-2];
        fib[i]=fib[i-1]+fib[i-2];
    }
    if(n<=2){
        printf("%d",a);
    }else if(n==3){
        printf("%d",2*a);
    }else{
        int u=(m-res[n-1].first*a)/res[n-1].second;
        printf("%d",res[x].first*a+res[x].second*u);
    }
}