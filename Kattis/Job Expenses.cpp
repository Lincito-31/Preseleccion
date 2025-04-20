#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int t,a;
ll sum=0;
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin >> t;
    while(t--){
        cin >> a;
        if(a<0){
            sum-=a;
        }
    }
    cout << sum;
}