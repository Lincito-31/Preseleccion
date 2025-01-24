#include <bits/stdc++.h>
using namespace std;
string x,y="";
int n;
vector<vector<int>> dp;
int solve(int posi,int racha){
    if(posi>=n){
        return 0;
    }
    if(racha>=3){
        racha=3;
    }
    if(dp[posi][racha]!=-1){
        return dp[posi][racha];
    }
    int res=0;
    if(y[posi]=='W'){
        res+=2;
        racha++;
        res+=solve(posi+1,racha);
        if(racha>=3){
            racha=3;
            res++;
        }
    }else{
        int op1=solve(posi+1,racha);
        int op2=solve(posi+1,0)+1;
        if(op1>=op2){
            res=op1;
        }else{
            res=op2;
        }
    }
    return dp[posi][racha]=res;
}
int main(){
    cin >> x;
    n=x.size();
    for(int i=0;i<n;i++){
        if(x[i]!='L'){
            y.push_back(x[i]);
        }
    }
    n=y.size();
    dp.assign(n,vector<int>(4,-1));
    printf("%d",solve(0,0));
}