#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int n,t,p,a;
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin >> t;
    while(t--){
        cin >> n >> p;
        vector<bool> posi(n+1,false);
        posi[0]=true;
        while(p--){
            cin >> a;
            for(int i=n;i-a>=0;i--){
                posi[i]=posi[i]|posi[i-a];
            }
        }
        if(posi[n]){
            cout << "YES\n";
        }else{
            cout << "NO\n";
        }
    }
}