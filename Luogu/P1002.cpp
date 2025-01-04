#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll a,b,x,y;
int main(){
    scanf("%lld%lld%lld%lld",&a,&b,&x,&y);
    ll table[a+2][b+2];
    table[a+1][b+1]=0;
    vector<pair<ll,ll>> atack={{x,y},{x-2,y-1},{x-1,y-2},{x-1,y+2},{x+2,y-1},{x+1,y-2},{x-2,y+1},{x+1,y+2},{x+2,y+1}};
    for(ll i=0;i<=a+1;i++){
        table[i][0]=0;
    }
    for(ll i=0;i<=b+1;i++){
        table[0][i]=0;
    }
    table[0][1]=1;
    for(ll i=1;i<a+2;i++){
        for(ll j=1;j<b+2;j++){
            table[i][j]=table[i][j-1]+table[i-1][j];
            for(ll k=0;k<9;k++){
                if(i-1==atack[k].first&&j-1==atack[k].second){
                    table[i][j]=0;
                }
            }
        }
    }
    printf("%lld",table[a+1][b+1]);
}