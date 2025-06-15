#include <bits/stdc++.h>
#define ALL(x) x.begin(),x.end()
#define MOD 1000000007
using namespace std;
int t,n,s,O,K,I,E;
vector<vector<vector<vector<vector<int>>>>> dp;
int maxi[4],queries[500001][4];
// exactamente i ovejas, suma K, I, E si estoy en pos o;
/*int solve(int i,int j,int k,int l,int o){
    if(dp[i][j][k][l][o]!=-1){
        return dp[i][j][k][l][o];
    }
    if(i<0 || j<0 || k<0 || l<0 || o<0){
        return 0;
    }
    if(i==0 && j==0 && k==0 && l==0 && o==0){
        return 1;
    }
    dp[i][j][k][l][o]=-1;
    if(solve(i,j,k,l,o-1)==1){
        return dp[i][j][k][l][o]=1;
    }
    for(int xx=1;xx<100;xx++){
        if(j-xx<0 || k-xx*a[o]<0 || l-xx*b[o]<0){
            break;
        }
        if(solve(i-1,j-xx,k-xx*a[o],l-xx*b[o],o-1)==1){
            return dp[i][j][k][l][o]=1;
        }
    }
    return dp[i][j][k][l][o]=0;
}*/
bool backtrack(int indice,int cantidad){
    
}
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin >> t;
    while(t--){
        cin >> n;
        maxi[0]=maxi[1]=maxi[2]=maxi[3]=0;
        vector<pair<int,int>> nums(n);
        for(int i=0;i<n;i++){
            cin >> nums[i].first;
        }
        for(int i=0;i<n;i++){
            cin >> nums[i].second;
        }
        sort(ALL(nums));
        cin >> s;
        backtrack(0,)
    }
}