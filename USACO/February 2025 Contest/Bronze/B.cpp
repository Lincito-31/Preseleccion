#include <bits/stdc++.h>
using namespace std;
int n,a;
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin >> n;
    vector<int> con(n+2),vac(n+2);
    for(int i=0;i<n;i++){
        cin >> a;
        con[++a]++;
    }
    for(int i=1;i<=n+1;i++){
        vac[i]=vac[i-1];
        if(con[i]==0){
            vac[i]++;
        }
    }
    for(int i=1;i<=n+1;i++){
        cout << max(vac[i-1],con[i]) << "\n";
    }
}