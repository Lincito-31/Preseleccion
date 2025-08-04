#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;
using namespace std;
#define eps 1e-9
typedef long double ld;
typedef long long ll;
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef tree<int,null_type,less<int>,rb_tree_tag,tree_order_statistics_node_update> indexed_set;
ll n,k;
vector<ll> nums;
pair<ld,ll> operator+(pair<ld,ll> x,pair<ld,ll> y){
    return {x.first+y.first,x.second+y.second};
}
pair<ld,ll> solve(ll penal){
    pair<ld,ll> dp[n];
    ll raiz=sqrt((ld)(nums[0]/penal));
    pair<ld,ll> op1,op2;
    if(raiz==0){
        op1={1e18,0};
    }else{
        op1={(ld)(nums[0]/raiz)+(ld)(raiz*penal),raiz};
    }
    raiz++;
    if(raiz==0){
        op2={1e18,0};
    }else{
        op2={(ld)(nums[0]/raiz)+(ld)(raiz*penal),raiz};
    }
    if(abs(op1.first-op2.first)<eps){
        dp[0]=op2;
    }else{
        dp[0]=min(op1,op2);
    }
    for(int i=1;i<n;i++){
        ll raiz=sqrt((ld)(nums[i]/penal));
        if(raiz==0){
            op1={1e18,0};
        }else{
            op1={(ld)(nums[i]/raiz)+(ld)(raiz*penal),raiz};
        }
        raiz++;
        if(raiz==0){
            op2={1e18,0};
        }else{
            op2={(ld)(nums[i]/raiz)+(ld)(raiz*penal),raiz};
        }
        if(abs(op1.first-op2.first)<eps){
            dp[i]=dp[i-1]+op2;
        }else{
            dp[i]=dp[i-1]+min(op1,op2);
        }
    }
    return dp[n-1];
}
int main(){
    //freopen("tallbarn.in","r",stdin);
    //freopen("tallbarn.out","w",stdout);
    cin >> n >> k;
    nums.resize(n);
    for(int i=0;i<n;i++){
        cin >> nums[i];
    }
    ll l=1,r=1e18;
    while(l<r){
        ll mid=(l+r+1)>>1;
        // mayor mid=menor k;
        if(solve(mid).second<=k){
            l=mid;
        }else{
            r=mid-1;
        }
    }
    cout << solve(l).first-k*l;
}