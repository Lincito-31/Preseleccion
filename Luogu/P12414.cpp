#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int t,n,m,a;
bool xd;
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin >> t;
    while(t--){
        xd=false;
        cin >> n >> m;
        vector<int> con(n,0);
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                cin >> a;
                con[--a]++;
            }
        }
        for(int i=0;i<n;i++){
            if(con[i]<m){
                xd=true;
            }
        }
        if(xd){
            cout << "Yes\n";
        }else{
            cout << "No\n";
        }
    }
}