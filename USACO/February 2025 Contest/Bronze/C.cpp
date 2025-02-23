#include <bits/stdc++.h>
using namespace std;
int t,n,k,mini;
vector<vector<int>> tamrepe;
vector<vector<int>> dp;
int solve(int x,int y){
    if(dp[x][y]!=1e5){
        return dp[x][y];
    }
    if(x==y){
        return 1;
    }
    if(tamrepe[x][y]==y-x+1){
        for(int i=x;i<y;i++){
            dp[x][y]=min(dp[x][y],solve(x,i)+solve(i+1,y));
        }
    }else{
        dp[x][y]=solve(x,x+tamrepe[x][y]-1);
    }
    return dp[x][y];
}
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin >> t;
    while(t--){
        cin >> n >> k;
        vector<int> nums(n);
        for(int i=0;i<n;i++){
            cin >> nums[i];
        }
        tamrepe.assign(n,vector<int>(n,-1));
        dp.assign(n,vector<int>(n,1e5));
        vector<int> temp;
        for(int i=0;i<n;i++){
            temp.clear();
            int canti=0,contador;
            for(int j=i;j<n;j++){
                temp.push_back(nums[j]);
                canti++;
                contador=0;
                for(int tempj=i;tempj<n;tempj++){
                    if(nums[tempj]!=temp[contador]){
                        break;
                    }
                    contador++;
                    //cout << j << " " << tempj << "\n";
                    if(contador>=canti){
                        if(tamrepe[i][tempj]==-1){
                            //cout << j << " " << tempj << " " << canti << "\n";
                            tamrepe[i][tempj]=canti;
                        }
                        contador=0;
                    }
                }
            }
        }
        int mini=4;
        if(solve(0,n-1)<=k){
            cout << "YES\n";
        }else{
            cout << "NO\n";
        }
    }
}