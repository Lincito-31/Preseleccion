// https://codeforces.com/contest/1733/problem/D2
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#define ALL(x) x.begin(),x.end()
using namespace __gnu_pbds;
using namespace std;
typedef pair<int,int> pii;
typedef tree<pii,null_type,less<pii>,rb_tree_tag,tree_order_statistics_node_update> indexed_set;
typedef vector<int> vi;
typedef long long ll;
ll t,n,x,y;
int main(){
    scanf("%lld",&t);
    while(t--){
        scanf("%lld %lld %lld",&n,&x,&y);
        char a[n+5],b[n+5];
        scanf("%s %s",a,b);
        ll res=0;
        vector<ll> err;
        for(int i=0;i<n;i++){
            if(a[i]!=b[i]){
                err.push_back(i);
            }
        }
        n=err.size();
        if(n%2==1){
            printf("-1\n");
        }else{
            if(n!=0){
                if(y<=x){
                    res=(n/2)*y;
                    if(n==2 && err[1]==err[0]+1){
                        res=min(2*y,x);
                    }
                }else{
                    vector<vector<ll>> dp(5002,vector<ll>(5002,1e18));
                    dp[n][0]=0;
                    dp[n-1][1]=0;
                    for(ll i=n-2;i>=0;i--){
                        dp[i][0]=min(dp[i+2][0]+(err[i+1]-err[i])*x,dp[i+1][1]+y);
                        for(ll j=1;j<5002;j++){
                            dp[i][j]=min(dp[i+2][j]+(err[i+1]-err[i])*x,min(dp[i+1][j + 1]+y,dp[i+1][j-1]));
                        }
                    }
                    res=dp[n-1][0];
                }
            }
            printf("%lld\n",res);
        }
    }
}
/*
La primera transición representa el caso en el que tomamos el par y lo conseguimos usando puros x, 
la segunda transición representa el caso en el que nosotros emparejamos la posición en la que 
estamos con otra que no necesariamente es la siguiente y la última transición representa el caso en 
el que hay algunos que aun no se emparejaron y lo emparejamos con el actual. Los casos base 
representan que hay solo uno más por emparejar y estamos en la última posición errada y el otro 
representa que ya no hay más posiciones erradas que emperejar.
*/