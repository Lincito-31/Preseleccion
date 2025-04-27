#include <bits/stdc++.h>
#define ALL(x) x.begin(),x.end()
using namespace std;
typedef long long ll;
int t;
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    while(cin >> t && t){
        while(t>9){
            int nue=0;
            while(t>0){
                nue+=t%10;
                t/=10;
            }
            t=nue;
        }
        cout << t << '\n';
    }
}