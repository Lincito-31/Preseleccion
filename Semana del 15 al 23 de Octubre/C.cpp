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
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin >> t;
    while(t--){
        cin >> n >> x >> y;
        cin >> a >> b;
        ll res=0;
        vector<ll> err;
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
                    vector<ll> dif(n);
                    for(int i=1;i<n;i++){
                        dif[i]=err[i]-err[i-1];
                    }
                }
            }
            cout << res << "\n";
        }
    }
}