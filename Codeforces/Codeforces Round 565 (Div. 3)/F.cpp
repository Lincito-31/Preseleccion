#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vll;
int n;
ll dp[200001][10],c,d,un[3],dos,tres,nu,maxi,k[200001];
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin >> n;
    for(int i=0;i<=200000;i++){
        for(int j=0;j<10;j++){
            dp[i][j]=-1e18;
        }
    }
    dp[0][0]=0;
    for(int i=1;i<=n;i++){
        cin >> k[i];
        un[0]=un[1]=un[2]=dos=tres=-1e18;
        for(int j=0;j<k[i];j++){
            cin >> c >> d;
            if(c==1){
                if(d>un[0]){
                    swap(d,un[0]);
                }
                if(d>un[1]){
                    swap(d,un[1]);
                }
                if(d>un[2]){
                    swap(d,un[2]);
                }
            }else if(c==2){
                dos=max(dos,d);
            }else{
                tres=max(tres,d);
            }
        }
        for(int j=0;j<10;j++){
            dp[i][j]=max(dp[i][j],dp[i-1][j]);
        }
        // es mejor tomar el 3?
        for(int j=1;j<10;j++){
            dp[i][j]=max(dp[i][j],dp[i-1][j-1]+tres);
        }
        dp[i][0]=max(dp[i][0],dp[i-1][9]+2*tres);
        // es mejor tomar el 2?
        for(int j=1;j<10;j++){
            dp[i][j]=max(dp[i][j],dp[i-1][j-1]+dos);
        }
        dp[i][0]=max(dp[i][0],dp[i-1][9]+2*dos);
        // es mejor tomar el 2 y un 1?
        for(int j=2;j<10;j++){
            dp[i][j]=max(dp[i][j],dp[i-1][j-2]+dos+un[0]);
        }
        dp[i][1]=max(dp[i][1],dp[i-1][9]+dos+un[0]+max(dos,un[0]));
        dp[i][0]=max(dp[i][0],dp[i-1][8]+dos+un[0]+max(dos,un[0]));
        // es mejor tomar un 1?
        for(int j=1;j<10;j++){
            dp[i][j]=max(dp[i][j],dp[i-1][j-1]+un[0]);
        }
        dp[i][0]=max(dp[i][0],dp[i-1][9]+2*un[0]);
        // dos 1?
        for(int j=2;j<10;j++){
            dp[i][j]=max(dp[i][j],dp[i-1][j-2]+un[1]+un[0]);
        }
        dp[i][1]=max(dp[i][1],dp[i-1][9]+un[1]+un[0]+max(un[1],un[0]));
        dp[i][0]=max(dp[i][0],dp[i-1][8]+un[1]+un[0]+max(un[1],un[0]));
        // tres 1?
        for(int j=3;j<10;j++){
            dp[i][j]=max(dp[i][j],dp[i-1][j-3]+un[1]+un[0]+un[2]);
        }
        dp[i][1]=max(dp[i][1],dp[i-1][8]+un[1]+un[0]+un[2]+max({un[1],un[0],un[2]}));
        dp[i][0]=max(dp[i][0],dp[i-1][7]+un[1]+un[0]+un[2]+max({un[1],un[0],un[2]}));
        dp[i][2]=max(dp[i][2],dp[i-1][9]+un[1]+un[0]+un[2]+max({un[1],un[0],un[2]}));
    }
    for(int i=0;i<10;i++){
        maxi=max(maxi,dp[n][i]);
    }
    cout << maxi;
}