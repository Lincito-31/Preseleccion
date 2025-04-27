#include <bits/stdc++.h>
#define ALL(x) x.begin(),x.end()
#define REV(x) x.rbegin(),x.rend()
using namespace std;
typedef long long ll;
int m,n,con,a;
bool xd;
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    while(cin >> n >> m){
        con=0;
        while(n--){
            xd=true;
            for(int i=0;i<m;i++){
                cin >> a;
                if(a==0){
                    xd=false;
                }
            }
            if(xd){
                con++;
            }
        }
        cout << con << '\n';
    }
}