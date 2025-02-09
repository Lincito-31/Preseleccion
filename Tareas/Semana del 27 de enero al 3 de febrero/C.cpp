#include <bits/stdc++.h>
#define MOD 1000000007
using namespace std;
int t,n;
string A,B,x,y;
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);cout.tie(NULL);
    cin >> t;
    while(t--){
        cin >> n >> x >> y;
        A="";
        B="";
        for(int i=0;i<n;i++){
            if(x[i]=='0'){
                A.clear();
            }else if(x[i]=='1'){
                continue;
            }else if(x[i]!='+'){
                x[i]='0';
            }
            A+=x[i];
        }
        for(int i=0;i<n;i++){
            if(y[i]=='0'){
                B.clear();
            }else if(y[i]=='1'){
                continue;
            }else if(y[i]!='+'){
                y[i]='0';
            }
            B+=y[i];
        }
        int tamA=A.size(),tamB=B.size();
        vector<vector<pair<int,int>>> dp(tamA+2,vector<pair<int,int>>(tamB+2,{0,0}));
        dp[0][0].first=1;
        for(int i=0;i<=tamA;i++){
            for(int j=0;j<=tamB;j++){
                dp[i][j+1].second+=dp[i][j].first;
                dp[i][j+1].second%=MOD;
                dp[i+1][j].first+=dp[i][j].first;
                dp[i+1][j].first%=MOD;
                dp[i][j+1].second+=dp[i][j].second;
                dp[i][j+1].second%=MOD;
                if(j==0 || i==tamA){
                    continue;
                }
                if(B[j-1]!=A[i]){
                    dp[i+1][j].first+=dp[i][j].second;
                    dp[i+1][j].first%=MOD;
                }
            }
        }
        cout << (dp[tamA][tamB].first+dp[tamA][tamB].second)%MOD << "\n";
    }
}