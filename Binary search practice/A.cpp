#include <bits/stdc++.h> 
using namespace std; 
typedef long long ll;
ll n,k,maxi=0,mini=0;
int main(){ 
    scanf("%lld%lld",&n,&k); 
    ll nums[n];
    for(ll i=0;i<n;i++){ 
        scanf("%lld",&nums[i]); 
        maxi+=nums[i];
        mini=max(mini,nums[i]);
    }
    while(mini<maxi){
        ll mid=(mini+maxi)>>1;
        ll now=0,con=0;
        for(int i=0;i<n;i++){
            if(now+nums[i]>mid){
                con++;
                if(con>k){
                    break;
                }
                now=nums[i];
            }else{
                now+=nums[i];
            }
        }
        con++;
        if(con>k){
            mini=mid+1;
        }else{
            maxi=mid;
        }
    }
    printf("%lld",mini);
}