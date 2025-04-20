#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n,q;
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin >> n >> q;
    vector<ll> objetos(n+1),dp(n+1,1e18);
    for(int i=1;i<=n;i++){
        cin >> objetos[i];
    }
    sort(objetos.begin(),objetos.end());
    dp[0]=0;
    for(int i=1;i<=n;i++){
        dp[i]=objetos[i]-q*objetos[i]/100+dp[i-1];
        if(i-2>=0){
            dp[i]=min((objetos[i]+objetos[i-1])-(q*(objetos[i]+objetos[i-1])/100)+dp[i-2],dp[i]);
        }
        if(i-3>=0){
            dp[i]=min(objetos[i]+objetos[i-1]+objetos[i-2]-min({objetos[i],objetos[i-1],objetos[i-2]})+dp[i-3],dp[i]);
        }
    }
    cout << dp[n];
}
/*
7 10 \\
300 200 200 300 100 300 200 \\
1090

3 20 \\
1000 500 100 \\
1280

4 0 \\
200 100 300 200 \\
600
*/
