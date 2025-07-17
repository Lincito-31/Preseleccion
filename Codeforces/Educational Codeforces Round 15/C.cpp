#include <bits/stdc++.h>
#define ALL(x) x.begin(),x.end()
using namespace std;
int n,m,mini=0;
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin >> n >> m;
    vector<int> city(n),tower(m);
    for(int i=0;i<n;i++){
        cin >> city[i];
    }
    for(int j=0;j<m;j++){
        cin >> tower[j];
    }
    for(int i=0;i<n;i++){
        auto p=lower_bound(ALL(tower),city[i]);
        int de=2e9,iz=2e9;
        if(p!=tower.end()){
            de=*p-city[i];
        }
        if(p!=tower.begin()){
            p--;
            iz=city[i]-*p;
        }
        mini=max(mini,min(iz,de));
    }
    cout << mini << ' ';
}