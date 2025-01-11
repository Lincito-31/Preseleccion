#include <bits/stdc++.h>
using namespace std;
int k,dp[50][100005];
bool visited[50][100005];
//Es posible formar un numero cuyo modk==modulo y suma de digitos de ese numero sea rest?
int possible(int rest,int modulo){
    if(dp[rest][modulo]!=0){
        return dp[rest][modulo];
    }
    if(visited[rest][modulo]){
        return dp[rest][modulo]=2;
    }
    visited[rest][modulo]=true;
    for(int i=0;i<10;i++){
        if(rest-i<0){
            break;
        }
        if(possible(rest-i,(modulo*10+i)%k)==1){
            return dp[rest][modulo]=1;
        }
    }
    return dp[rest][modulo]=2;
}
int main(){
    scanf("%d",&k);
    int cop=k,sum=0;
    while(cop>0){
        sum+=cop%10;
        cop/=10;
    }
    for(int i=0;i<=sum;i++){
        for(int j=0;j<=k;j++){
            dp[i][j]=0;
            visited[i][j]=false;
        }
    }
    dp[0][0]=1;
    for(int i=1;i<=sum;i++){
        if(possible(i,0)==1){
            printf("%d",i);
            return 0;
        }
    }
}