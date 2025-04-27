#include <bits/stdc++.h>
#define ALL(x) x.begin(),x.end()
using namespace std;
typedef long long ll;
int t,con,sum;
string s;
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin >> t;
    while(t--){
        cin >> s;
        con=sum=0;
        for(int i=0;i<s.size();i++){
            if(s[i]=='O'){
                con++;
                sum+=con;
            }else{
                con=0;
            }
        }
        cout << sum << '\n';
    }
}