#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int t,a,speed,timee;
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    while(cin >> t && t!=-1){
        int sum=0;
        int last=0;
        while(t--){
            cin >> speed >> timee;
            sum+=speed*(timee-last);
            last=timee;
        }
        cout << sum << " miles\n";
    }
}