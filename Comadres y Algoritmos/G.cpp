#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int n;
ll x;
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin >> n;
    vector<ll> nums(n),dif(n);
    cin >> nums[0];
    dif[0]=-1;
    for(int i=1;i<n;i++){
        cin >> nums[i];
        dif[i]=nums[i]-nums[i-1];
    }
    ll res=2*n-1;
    ll con=1;
    for(int i=1;i<n;i++){
        if(dif[i]==dif[i-1]){
            con++;
        }else{
            if(con>=2){
                res+=(con+1)*(con+2)/2;
                res-=(2*(con+1)-1);
            }
            con=1;
        }
    }
    if(con>=2){
        res+=(con+1)*(con+2)/2;
        res-=(2*(con+1)-1);
    }
    con=1;
    cout << res;
}