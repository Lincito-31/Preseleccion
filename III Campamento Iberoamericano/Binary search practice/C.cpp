#include <bits/stdc++.h>
using namespace std; 
typedef long long ll;
typedef pair<ll,ll> pll;
ll ax,bx,ay,by,sumx=0,sumy=0,n;
char ch;
pll operator +(pll a,pll b){
    return {a.first+b.first,a.second+b.second};
}
int main(){ 
    scanf("%lld%lld%lld%lld%lld",&ax,&ay,&bx,&by,&n);
    pll nums[n+1],psum[n+1];
    nums[0]=psum[0]={0,0};
    for(int i=1;i<=n;i++){
        scanf(" %c",&ch);
        if(ch=='U'){
            nums[i]={0,1};
            sumy++;
        }else if(ch=='D'){
            nums[i]={0,-1};
            sumy--;
        }else if(ch=='L'){
            nums[i]={-1,0};
            sumx--;
        }else{
            nums[i]={1,0};
            sumx++;
        }
        psum[i]=psum[i-1]+nums[i];
    }
    ll l=0,r=1e18;
    while(l<r){
        ll mid=(l+r)>>1;
        ll cantvuel=mid/n,sob=mid%n;
        ll tempx=ax+cantvuel*sumx,tempy=ay+cantvuel*sumy;
        tempx+=psum[sob].first;
        tempy+=psum[sob].second;
        ll manhatandist=abs(tempx-bx)+abs(tempy-by);
        if(manhatandist<=mid){
            r=mid;
        }else{
            l=mid+1;
        }
    }
    printf("%lld",(l==1e18)?-1:l);
}