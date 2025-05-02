#include <bits/stdc++.h>
#define ALL(x) x.begin(),x.end()
using namespace std;
int ss[3],s[2],con,a,b;
bool used[52],xd;
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    while(cin >> ss[0] >> ss[1] >> ss[2] >> s[0] >> s[1],ss[0]){
        xd=false;
        memset(used,false,sizeof used);
        ss[0]--;
        ss[1]--;
        ss[2]--;
        s[0]--;
        s[1]--;
        used[ss[0]]=used[ss[1]]=used[ss[2]]=used[s[0]]=used[s[1]]=true;
        a=b=con=0;
        sort(ss,ss+3);
        sort(s,s+2);
        for(int i=0;i<3;i++){
            if(ss[i]>s[0]){
                a=ss[i];
                ss[i]=0;
                con++;
                break;
            }
        }
        for(int i=0;i<3;i++){
            if(ss[i]>s[1]){
                b=ss[i];
                ss[i]=0;
                con++;
                break;
            }
        }
        if(con==2){
            cout << -1 << '\n';
        }else{
            if(con==0){
                for(int i=0;i<52;i++){
                    if(used[i]){
                        continue;
                    }else{
                        cout << i+1 << '\n';
                        xd=true;
                        break;
                    }
                }
            }else{
                for(int i=0;i<52;i++){
                    if(used[i] || i<=max({ss[0],ss[1],ss[2]})){
                        continue;
                    }else{
                        cout << i+1 << '\n';
                        xd=true;
                        break;
                    }
                }
            }
            if(!xd){
                cout << -1 << '\n';
            }
        }
    }
}