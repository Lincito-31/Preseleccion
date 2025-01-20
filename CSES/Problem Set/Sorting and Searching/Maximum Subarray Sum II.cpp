#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int n,a,b,ini=0;
ll sum=0,maxi=0;
int main(){
    scanf("%d%d%d",&n,&a,&b);
    vector<ll> nums(n);
    for(int i=0;i<n;i++){
        scanf("%lld",&nums[i]);
    }
    for(int i=0;i<a;i++){
        sum+=nums[i];
    }
    maxi=sum;
    for(int i=a;i<n;i++){
        sum+=nums[i];
        while(i-ini+1>b){
            sum-=nums[ini];
            ini++;
        }
        if(i-ini+1<=b){
            maxi=max(sum,maxi);
        }
        while(i-ini+1>a && nums[ini]<=0){
            sum-=nums[ini];
            maxi=max(sum,maxi);
            ini++;
        }
    }
    printf("%lld",maxi);
}