#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int t,n,m,con;
string x;
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);cout.tie(NULL);
    cin >> t;
    while(t--){
        cin >> n >> m;
        if(n==m){
            cout << "YES";
        }else if(n==1){
            cout << "NO";
        }else if(n<=3){
            if(m<=3){
                cout << "YES";
            }else{
                cout << "NO";
            }
        }else{
            cout << "YES";
        }
        cout << "\n";
    }
}