#include <bits/stdc++.h>
#define ALL(x) x.begin(),x.end()
using namespace std;
typedef long long ll;
ll n,k;
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin >> n >> k;
    ll arr[n];
    for(ll i=0;i<n;i++){
        cin >> arr[i];
    }
    sort(arr,arr+n);
    ll l=1,r=3e9;
    while(l<r){
        ll mid=(l+r+1)>>1;
        ll cant=0;
        for(ll i=n/2;i<n;i++){
            cant+=max(0ll,mid-arr[i]);
            if(cant>k){
                break;
            }
        }
        if(cant>k){
            r=mid-1;
        }else{
            l=mid;
        }
    }
    cout << l;
}