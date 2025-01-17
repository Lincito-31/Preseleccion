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
        ll resul=1e9;
        for(int i=1;i<=n && resul>0;i++){
            for(int j=1;j<=m && resul>0;j++){
                if(mat[i][j]==0){
                    continue;
                }
                ll l=0,r=max(n,m);
                while(l<r){
                    ll mid=(l+r)>>1;
                    ll x1=i-mid-1,y1=j-mid-1;
                    ll x2=i-mid-1,y2=j+mid;
                    ll x3=i+mid,y3=j-mid-1;
                    ll x4=i+mid,y4=j+mid;
                    x1=max(x1,0ll);
                    y1=max(y1,0ll);
                    x2=max(x2,0ll);
                    y2=min(y2,m);
                    x3=min(x3,n);
                    y3=max(y3,0ll);
                    x4=min(x4,n);
                    y4=min(y4,m);
                    ll suma=psum[x4][y4]-psum[x2][y2]-psum[x3][y3]+psum[x1][y1];
                    if(suma>k){
                        r=mid;
                    }else{
                        l=mid+1;
                    }
                }
                ll mid=(l+r)>>1;
                ll x1=i-mid-1,y1=j-mid-1;
                ll x2=i-mid-1,y2=j+mid;
                ll x3=i+mid,y3=j-mid-1;
                ll x4=i+mid,y4=j+mid;
                x1=max(x1,0ll);
                y1=max(y1,0ll);
                x2=max(x2,0ll);
                y2=min(y2,m);
                x3=min(x3,n);
                y3=max(y3,0ll);
                x4=min(x4,n);
                y4=min(y4,m);
                ll suma=psum[x4][y4]-psum[x2][y2]-psum[x3][y3]+psum[x1][y1];
                if(suma>k){
                    resul=min(resul,l);
                    //cout << i << " " << j << " " << resul << "\n";
                }
            }
        }
        if(resul==1e9){
            printf("-1\n");
        }else{
            printf("%lld\n",resul);
        }
    }
}