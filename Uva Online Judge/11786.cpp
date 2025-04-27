#include <bits/stdc++.h>
#define ALL(x) x.begin(),x.end()
using namespace std;
typedef long long ll;
int t,altnow,sum;
vector<int> alt(20001,1e9);
string s;
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin >> t;
    while(t--){
        sum=0;
        altnow=10000;
        alt.assign(20001,1e9);
        cin >> s;
        if(s[0]=='\\'){
            alt[altnow]=0;
        }
        for(int i=1;i<s.size();i++){
            if(s[i]=='/'){
                if(s[i-1]=='/'){
                    altnow++;
                }
                sum+=max(0,i-alt[altnow]);
            }else if(s[i]=='\\'){
                if(s[i-1]!='/'){
                    altnow--;
                }
                alt[altnow]=i;
            }else{
                if(s[i-1]=='/'){
                    altnow++;
                }
            }
        }
        cout << sum << '\n';
    }
}