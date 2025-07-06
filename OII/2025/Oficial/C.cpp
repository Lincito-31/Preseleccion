#include <bits/stdc++.h>
#define ALL(x) x.begin(),x.end()
using namespace std;
typedef long long ll;
int n,t,q,O,K,I,E;
ll FI[1000000],FE[1000000];
// O K I E hasta n
/*map<int,map<int,int>> dp[105][15];
int solve(int pos,int y,int z,int w){
    if(y==0 && z==0 && w==0){
        return 1;
    }
    if(pos<0 || y<0 || z<0 || w<0){
        return 2;
    }
    if(dp[pos][y][z][w]!=0){
        return dp[pos][y][z][w];
    }
    if(solve(pos-1,y,z,w)==1){
        return dp[pos][y][z][w]=1;
    }
    if(solve(pos-1,y-1,z-FI[pos],w-FE[pos])==1){
        return dp[pos][y][z][w]=1;
    }
    return dp[pos][y][z][w]=2;
}*/
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin >> t;
    while(t--){
        cin >> n;
        for(int i=0;i<n;i++){
            cin >> FI[i];
        }
        for(int i=0;i<n;i++){
            cin >> FE[i];
        }
        bool dp[11][101][101]={false};
        dp[0][0][0]=true;
        for(int j=0;j<n;j++){
            if(FI[j]>100 || FE[j]>100){
                continue;
            }
            for(int k=1;k<=10;k++){
                for(int i=FI[j];i<=100;i++){
                    for(int e=FE[j];e<=100;e++){
                        if(dp[k-1][i-FI[j]][e-FE[j]]){
                            dp[k][i][e]=true;
                        }
                    }
                }
            }
        }
        cin >> q;
        while(q--){
            cin >> O >> K >> I >> E;
            if(O>n || K>O){
                cout << "NO\n";
                continue;
            }
            if(dp[K][I][E]==1){
                cout << "YES\n";
            }else{
                cout << "NO\n";
            }
        }
    }
}