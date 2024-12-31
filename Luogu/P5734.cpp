#include <bits/stdc++.h>
#define FASTIO ios_base::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL)
#define REV(x) x.rbegin(),x.rend()
using namespace std;
typedef long long ll;
typedef vector<int> vi;
int q,t,a,b;
string x,y;
int main(){
    FASTIO;
    cin >> q >> x;
    while(q--){
        cin >> t;
        if(t==1){
            cin >> y;
            x.append(y);
            cout << x << "\n";
        }else if(t==2){
            cin >> a >> b;
            x=x.substr(a,b);
            cout << x << "\n";
        }else if(t==3){
            cin >> a >> y;
            x.insert(a,y);
            cout << x << "\n";
        }else{
            cin >> y;
            if(x.find(y)!=-1){
                cout << x.find(y) << "\n";
            }else{
                cout << "-1\n";
            }
        }
    }
}