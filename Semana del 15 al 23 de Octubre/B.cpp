// https://codeforces.com/gym/104875/attachments  problem J
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#define ALL(x) x.begin(),x.end()
using namespace __gnu_pbds;
using namespace std;
typedef pair<int,int> pii;
typedef long long ll;
typedef tree<pii,null_type,less<pii>,rb_tree_tag,tree_order_statistics_node_update> indexed_set;
typedef vector<int> vi;
typedef vector<ll> vll;
ll n,a,t;
int main(){
    scanf("%lld",&n);
    vector<vll> nums(n,vll(3));
    vll res(n);
    for(ll i=0;i<n;i++){
        scanf("%lld %lld",&a,&t);
        t+=a;
        nums[i]={a,t,i};
    }
    sort(ALL(nums));
    for(ll i=1;i<n;i++){
        if(nums[i][0]==nums[i-1][0]){  
            ll temp=nums[i][1];
            ll temp2=nums[i][2];
            nums[i][1]=nums[i-1][1];
            nums[i][2]=nums[i-1][2];
            nums[i-1][1]=temp;
            nums[i-1][2]=temp2;
        }
    }
    vector<vector<pair<ll,ll>>> cant(n,vector<pair<ll,ll>>(1,{0,-1}));
    cant[0].push_back({nums[0][1],nums[0][2]});
    for(ll i=1;i<n;i++){
        ll limi=0,limd=n-1;
        while(limi!=limd){
            ll mid=(limi+limd)/2;
            if(nums[i][1]<=cant[mid].back().first){
                limi=mid+1;
            }else{
                limd=mid;
            }
        }
        cant[limi].push_back({nums[i][1],nums[i][2]});
    }
    for(ll i=0;i<n;i++){
        for(ll j=1;j<cant[i].size();j++){
            res[cant[i][j].second]=i;
        }
    }
    for(ll i=0;i<n;i++){
        printf("%lld ",res[i]);
    }
}
