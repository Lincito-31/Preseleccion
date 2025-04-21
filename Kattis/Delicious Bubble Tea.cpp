#include <bits/stdc++.h>
#define ALL(x) x.begin(),x.end()
using namespace std;
typedef long long ll;
int n,m,mini=1e9,x,tot;
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin >> n;
    int a[n];
    for(int i=0;i<n;i++){
        cin >> a[i];
    }
    cin >> m;
    int b[m];
    for(int i=0;i<m;i++){
        cin >> b[i];
    }
    for(int i=0;i<n;i++){
        cin >> m;
        while(m--){
            cin >> x;
            mini=min(mini,a[i]+b[x-1]);
        }
    }
    cin >> tot;
    cout << max(0,tot/mini-1);
}