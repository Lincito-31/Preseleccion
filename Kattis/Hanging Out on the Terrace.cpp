#include <bits/stdc++.h>
#define ALL(x) x.begin(),x.end()
using namespace std;
typedef long long ll;
int k,n,a,con,canti;
string event;
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin >> k >> n;
    while(n--){
        cin >> event >> a;
        if(event=="enter"){
            if(con+a<=k){
                con+=a;
            }else{
                canti++;
            }
        }else{
            con-=a;
        }
    }
    cout << canti;
}