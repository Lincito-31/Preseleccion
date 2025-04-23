#include <bits/stdc++.h>
#define ALL(x) x.begin(),x.end()
using namespace std;
typedef long long ll;
int a,b,c,x;
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    while (cin >> a && a){
        bool xd=true;
        cin >> b;
        vector<bool> exi(10000,false);
        while(a--){
            cin >> x;
            exi[x]=true;
        }
        while(b--){
            cin >> a >> c;
            int con=0;
            while(a--){
                cin >> x;
                if(exi[x]){
                    con++;
                }
            }
            if(con<c){
                xd=false;
            }
        }
        if(xd){
            cout << "yes\n";
        }else{
            cout << "no\n";
        }
    }
}