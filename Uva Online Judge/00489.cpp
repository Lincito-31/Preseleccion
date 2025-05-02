#include <bits/stdc++.h>
#define ALL(x) x.begin(),x.end()
using namespace std;
int a,con,need,canti;
string s,t;
bool used[26],used2[26],xd;
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    while(cin >> a,a!=-1){
        xd=false;
        con=canti=need=0;
        memset(used,false,sizeof used);
        memset(used2,false,sizeof used2);
        cout << "Round " << a << '\n';
        cin >> s >> t;
        for(int i=0;i<s.size();i++){
            used[s[i]-'a']=true;
        }
        for(int i=0;i<26;i++){
            if(used[i]){
                con++;
            }
        }
        for(int i=0;i<t.size();i++){
            if(used2[t[i]-'a']){
                continue;
            }
            used2[t[i]-'a']=true;
            canti++;
            if(used[t[i]-'a']){
                need++;
                canti--;
            }
            if(need==con){
                cout << "You win.\n";
                xd=true;
                break;
            }
            if(canti>=7){
                cout << "You lose.\n";
                xd=true;
                break;
            }
        }
        if(!xd){
            cout << "You chickened out.\n";
        }
    }
}