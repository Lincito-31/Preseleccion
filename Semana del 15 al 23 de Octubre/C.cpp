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
string a,b;
vector<ll> err;
vector<vector<ll>> mat;
/*ll dp(ll a,ll b){
    if(mat[a][b]!=0){
        return mat[a][b];
    }
    if(b==a+1){
        mat[a][b]=min((err[b]-err[a])*x,y);
        return mat[a][b];
        //caso base
    }
    if((err[a+1]-err[a])*x>=y){
        mat[a][b]=y+dp(a+1,b-1);
        return mat[a][b];
    }
    if((err[b]-err[a])*x<=y){
        mat[a][b]=(err[a+1]-err[a])*x+dp(a+2,b);
        return mat[a][b];
    }
    ll op1=min((err[a+1]-err[a])*x,y)+dp(a+2,b);
    ll op2=min((err[b]-err[a])*x,y)+dp(a+1,b-1);
    mat[a][b]=min(op1,op2);
    return mat[a][b];
}*/
// caso tricky 1,4,7,[16,17],19
/*
1,7,21,100, 10000,100001
*/
ll dp(ll a,ll b){
    if(a>b){
        return 0;
    }
    if(mat[a][b]!=1e18){
        return mat[a][b];
    }
    for(int i=a+1;i<=b;i+=2){
        mat[a][b]=min(mat[a][b],min((err[i]-err[a])*x,y)+dp(a+1,i-1)+dp(i+1,b));
    }
    return mat[a][b];
}
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin >> t;
    while(t--){
        cin >> n >> x >> y;
        cin >> a >> b;
        ll res=0;
        err.clear();
        mat.clear();
        for(int i=0;i<n;i++){
            if(a[i]!=b[i]){
                err.push_back(i);
            }
        }
        n=err.size();
        if(n%2==1){
            cout << "-1\n";
        }else{
            if(n!=0){
                if(y<x){
                    res=(n/2)*y;
                    if(n==2 && err[1]==err[0]+1){
                        res=min(2*y,x);
                    }
                }else{
                    mat.assign(n,vector<ll>(n,1e18));
                    res=dp(0,n-1);
                }
            }
            cout << res << "\n";
        }
    }
}