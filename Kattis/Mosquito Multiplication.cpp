#include <bits/stdc++.h>
#define ALL(x) x.begin(),x.end()
using namespace std;
typedef long long ll;
int m,p,l,e,r,s,n;
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    while(cin >> m >> p >> l >> e >> r >> s >> n){
        for(int i=0;i<n;i++){
            int nue=p/s;
            p=l/r;
            l=e*m;
            m=nue;
        }
        cout << m << '\n';
    }
}