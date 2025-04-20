#include <bits/stdc++.h>
#define ALL(x) x.begin(),x.end()
using namespace std;
typedef long long ll;
int a,b,c,d;
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    while(cin >> a >> b >> c >> d && !(a==0 && b==0 && c==0 && d==0)){
        int canti=1080;
        if(a>=b){
            canti+=(a-b)*9;
        }else{
            canti+=9*(40-b+a);
        }
        if(c>=b){
            canti+=(c-b)*9;
        }else{
            canti+=9*(40-b+c);
        }
        if(d<=c){
            canti+=(c-d)*9;
        }else{
            canti+=9*(40-d+c);
        }
        cout << canti << "\n";
    }
}