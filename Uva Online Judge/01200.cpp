#include <bits/stdc++.h>
using namespace std;
int t;
string s;
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin >> t;
    while(t--){
        cin >> s;
        bool nega=false,lol=false;
        int x=0,a=-1e9,d=0;
        s.push_back('y');
        for(int i=0;i<s.size();i++){
            if(s[i]>='0' && s[i]<='9'){
                if(a==-1e9){
                    a=0;
                }
                a*=10;
                a+=s[i]-48;
            }else if(s[i]=='x' && !lol){
                if(a==-1e9){
                    a=1;
                }
                if(nega){
                    nega=false;
                    a*=-1;
                }
                x+=a;
                a=-1e9;
            }else if((s[i]=='+' || s[i]=='-') && !lol){
                if(nega){
                    nega=false;
                    a*=-1;
                }
                if(a!=-1e9){
                    d-=a;
                }
                a=-1e9;
                if(s[i]=='-'){
                    nega=true;
                }
            }else if(s[i]=='='){
                lol=true;
                if(nega){
                    nega=false;
                    a*=-1;
                }
                if(a!=-1e9){
                    d-=a;
                }
                a=-1e9;
            }else if(s[i]=='x'){
                if(a==-1e9){
                    a=1;
                }
                if(nega){
                    nega=false;
                    a*=-1;
                }
                x-=a;
                a=-1e9;
            }else{
                if(nega){
                    nega=false;
                    a*=-1;
                }
                if(a!=-1e9){
                    d+=a;
                }
                a=-1e9;
                if(s[i]=='-'){
                    nega=true;
                }
            }
        }
        //cout << x << ' ' << d << '\n';
        if(x==0 && d==0){
            cout << "IDENTITY\n";
        }else if(x==0){
            cout << "IMPOSSIBLE" << '\n';
        }else{
            if(d/x<0){
                if((double)d/x<(int)d/x){
                    cout << d/x-1 << '\n';
                }else{
                    cout << d/x << '\n';
                }
            }else{
                cout << d/x << '\n';
            }
        }
    }
}