#include <bits/stdc++.h>
#define ALL(x) x.begin(),x.end()
using namespace std;
int t,y,x;
string s;
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin >> t;
    for(int i=1;i<=t;i++){
        y=0;
        stack<string> sta;
        cout << "Case " << i << ": ";
        for(int j=0;j<27;j++){
            cin >> s;
            sta.push(s);
        }
        for(int j=0;j<3;j++){
            string tope=sta.top();
            sta.pop();
            if(tope[0]>='2' && tope[0]<='9'){
                x=tope[0]-48;
            }else{
                x=10;
            }
            for(int k=0;k<10-x;k++){
                sta.pop();
            }
            y+=x;
        }
        for(int j=0;j<25;j++){
            cin >> s;
            sta.push(s);
        }
        int con=sta.size();
        while(con>y){
            con--;
            sta.pop();
        }
        cout << sta.top() << '\n';
    }
}