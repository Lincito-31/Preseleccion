#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll t,n,m,k;
int main(){
    scanf("%lld",&t);
    while(t--){
        scanf("%lld%lld%lld",&n,&m,&k);
        vector<vector<ll>> mat(n+1,vector<ll>(m+1,0)),psum(n+1,vector<ll>(m+1,0));
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                scanf("%lld",&mat[i][j]);
            }
        }
        //init prefisum;
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                psum[i][j]=psum[i][j-1]+mat[i][j];
            }
        }
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                psum[i][j]+=psum[i-1][j];
            }
        }
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                ll l=0,r=max(n,m);
                while(l<r){
                    ll mid=(l+r)>>1;
                    ll x1=i-mid-1,y1=j-mid-1;
                    ll x2=i-mid-1,y2=j+mid;
                    ll x3=i+mid,y3=j-mid-1;
                    ll x4=i+mid,y4=j+mid;
                    x1=max(x1,0ll);
                    if(y1<0){
                        y1=0;
                    }
                    if(x2<0){
                        x2=0;
                    }
                    if(y2>m){
                        y2=m;
                    }

                }
            }
        }
    }
}