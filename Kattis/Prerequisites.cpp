#include <bits/stdc++.h>
#define ALL(x) x.begin(),x.end()
using namespace std;
typedef long long ll;
int t,a,l=1;
bool xd;
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin >> t;
    while(t--){
        cin >> a;
        while(l<a){
            xd=true;
            cout << l++ << '\n';
        }
        l++;
    }
    if(!xd){
        cout << "good job";
    }
}