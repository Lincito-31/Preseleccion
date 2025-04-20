#include <bits/stdc++.h>
#define ALL(x) x.begin(),x.end()
using namespace std;
typedef long long ll;
int l,n,now,x;
char t;
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin >> l >> n;
    l--;
    while(n--){
        cin >> x >> t;
        now+=x;
        if(now>=210){
            cout << l+1;
            return 0;
        }
        if(t=='T'){
            l++;
            l%=8;
        }
    }
}