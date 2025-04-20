#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int t,ante,now;
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin >> t;
    while(t--){
        ll sum=0;
        cin >> ante;
        while(cin >> now && now!=0){
            if(now-2*ante>0){
                sum+=now-2*ante;
            }
            ante=now;
        }
        cout << sum << "\n";
    }
}