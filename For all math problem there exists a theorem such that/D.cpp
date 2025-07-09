#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n,k,q,a,b,con;
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin >> n >> k >> q;
    while(q--){
        con=0;
        cin >> a >> b;
        if(k==1){
            cout << abs(b-a) << '\n';
            continue;
        }
        a--;b--;
        while(a!=b){
            if(a>b){
                swap(a,b);
            }
            b=(b-1)/k;
            con++;
        }
        cout << con << '\n';
    }    
}