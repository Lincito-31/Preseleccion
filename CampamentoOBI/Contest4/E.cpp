#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int n,d,maxi=1,a;
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin >> n >> d;
    if(d==n){
        set<int> lis;
        for(int i=0;i<n;i++){
            cin >> a;
            auto p=lis.lower_bound(a);
            if(p!=lis.end()){
                lis.erase(p);
            }
            lis.insert(a);
        }
        cout << lis.size();
        return 0;
    }
    vector<int> nums(n),dp(n,1);
    for(int i=0;i<n;i++){
        cin >> nums[i];
    }
    dp[0]=1;
    for(int i=1;i<n;i++){
        for(int j=1;j<=d && i-j>=0;j++){
            if(nums[i]>=nums[i-j]){
                dp[i]=max(dp[i],dp[i-j]+1);
            }
        }
        maxi=max(maxi,dp[i]);
        //cout << dp[i] <<" ";
    }
    cout << maxi;
}
/*
7 1
100 600 600 200 300 500 500
3

6 6
100 500 200 400 600 300
4

11 2
1 4 4 2 2 4 9 5 7 0 3
4
*/