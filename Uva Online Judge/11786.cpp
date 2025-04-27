#include <bits/stdc++.h>
#define ALL(x) x.begin(),x.end()
using namespace std;
typedef long long ll;
int t,con;
double l,w,h,k;
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin >> t;
    while(t--){
        cin >> l >> w >> h >> k;
        if(((l<=56 && w<=45 && h<=25)||((l+w+h)<=125))&& k<=7){
            cout << 1 << '\n';
            con++;
        }else{
            cout << 0 << '\n';
        }
    }
    cout << con << '\n';
}