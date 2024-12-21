#include <bits/stdc++.h>
#define ALL(x) x.begin(),x.end()
#define REV(x) x.rbegin(),x.rend()
using namespace std;
typedef vector<int> vi;
typedef pair<int,int> pii;
typedef long long ll;
typedef vector<ll> vll;
ll t,n;
int main(){
    scanf("%lld",&t);
    while(t--){
        scanf("%lld",&n);
        vll div;
        for(ll i=2;i*i<=n;i++){
            if(n%i==0){
                n/=i;
                div.push_back(i);
                i--;
            }
        }
        if(n>1){
            div.push_back(n);
        }
        map<ll,ll> cant;
        for(ll i=0;i<div.size();i++){
            cant[div[i]]++;
        }
        vector<pair<ll,ll>> nums;
        vll res;
        for(auto u:cant){
            nums.push_back({u.second,u.first});
        }
        sort(REV(nums));
        ll now=nums[0].second;
        for(int i=0;i<nums.size()-1;i++){
            while(nums[i].first>nums[i+1].first){
                res.push_back(now);
                nums[i].first--;
            }
            now*=nums[i+1].second;
        }
        while(nums.back().first>0){
            res.push_back(now);
            nums.back().first--;
        }
        printf("%d\n",res.size());
        for(int i=0;i<res.size();i++){
            printf("%lld ",res[i]);
        }
        printf("\n");
    }
}