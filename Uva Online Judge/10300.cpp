#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int t,n;
ll a,c,sum;
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin >> t;
    while(t--){
        sum=0;
        cin >> n;
        while(n--){
            cin >> a >> c >> c;
            sum+=a*c;
        }
        cout << sum << '\n';
    }
}