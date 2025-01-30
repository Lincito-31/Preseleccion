#include <bits/stdc++.h>
using namespace std;
int t,n;
int main(){
    scanf("%d",&t);
    while(t--){
        scanf("%d",&n);
        vector<vector<int>> mat(n+1,vector<int>(n+1)),jM(n+1,vector<int>(n+1)),M(n+1,vector<int>(n+1)),iM(n+1,vector<int>(n+1));
        for(int i=1;i<=n;i++){
            for(int j=1;j<=n;j++){
                scanf("%d",&mat[i][j]);
            }
        }
    }
}