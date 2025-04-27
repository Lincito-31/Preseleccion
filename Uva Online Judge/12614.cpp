#include <bits/stdc++.h>
#define ALL(x) x.begin(),x.end()
using namespace std;
typedef long long ll;
int t,lastd,lastr,mini;
string s;
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    while(cin >> t,t){
        cin >> s;
        lastd=lastr=-1e9;
        mini=1e9;
        for(int i=0;i<t;i++){
            if(s[i]=='D'){
                mini=min(mini,i-lastr);
                lastd=i;
            }else if(s[i]=='R'){
                mini=min(mini,i-lastd);
                lastr=i;
            }else if(s[i]=='Z'){
                mini=0;
                break;
            }
        }
        cout << mini << '\n';
    }
}