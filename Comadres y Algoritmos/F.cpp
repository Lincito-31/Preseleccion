#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int n;
ll x;
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin >> n;
    vector<ll> nums(n);
    ll sum=0;
    for(int i=0;i<n;i++){
        cin >> nums[i];
        sum+=nums[i];
    }
    cin >> x;
    ll res=(ll)(x/sum)*n;
    x%=sum;
    for(int i=0;x>=0;x-=nums[i],i++,res++);
    cout << res;
}