#include <bits/stdc++.h>
#define ALL(x) x.begin(),x.end()
using namespace std;
typedef long long ll;
int A,B,n,C,mini=1e9,pos;
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin >> n >> A >> B;
    for(int i=3;i<=n;i++){
        cin >> C;
        if(mini>max(A,C)){
            mini=max(A,C);
            pos=i-2;
        }
        A=B;
        B=C;
    }
    cout << pos << ' ' << mini;
}