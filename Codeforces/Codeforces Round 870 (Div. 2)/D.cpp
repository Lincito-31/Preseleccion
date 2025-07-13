#include <bits/stdc++.h>
#define ALL(x) x.begin(),x.end()
using namespace std;
typedef long long ll;
int n,t,nums[100002],psum[100002],ssum[100002],maxi;
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin >> t;
    while(t--){
        cin >> n;
        maxi=0;
        for(int i=1;i<=n;i++){
            cin >> nums[i];
        }
        psum[1]=nums[1]+1;
        ssum[n]=nums[n]-n;
        for(int i=2;i<=n;i++){
            psum[i]=max(psum[i-1],nums[i]+i);
        }
        for(int i=n-1;i>=2;i--){
            ssum[i]=max(ssum[i+1],nums[i]-i);
            maxi=max(maxi,psum[i-1]+ssum[i+1]+nums[i]);
        }
        cout << maxi << '\n';
    }
}