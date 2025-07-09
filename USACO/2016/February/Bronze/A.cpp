#include <bits/stdc++.h>
#define ALL(x) x.begin(),x.end()
using namespace std;
int x,y,m,maxi;
bool dp[1001];
int main(){
    ifstream in("pails.in");
    ofstream out("pails.out");
    dp[0]=true;
    in >> x >> y >> m;
    for(int i=min(x,y);i<=m;i++){
        if(i>=x){
            dp[i]|=dp[i-x];
        }
        if(i>=y){
            dp[i]|=dp[i-y];
        }
        if(dp[i]){
            maxi=i;
        }
    }
    out << maxi;
}