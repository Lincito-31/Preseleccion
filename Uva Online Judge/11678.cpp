#include <bits/stdc++.h>
#define ALL(x) x.begin(),x.end()
using namespace std;
int a,b,x,con;
set<int> p,s;
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    while(cin >> a >> b,a+b){
        p.clear();
        s.clear();
        con=0;
        for(int i=0;i<a;i++){
            cin >> x;
            p.insert(x);
        }
        for(int j=0;j<b;j++){
            cin >> x;
            s.insert(x);
        }
        for(auto u:s){
            if(p.count(u)){
                con++;
            }
        }
        cout << min(p.size(),s.size())-con << '\n';
    }
}