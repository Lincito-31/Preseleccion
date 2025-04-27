#include <bits/stdc++.h>
#define ALL(x) x.begin(),x.end()
using namespace std;
typedef long long ll;
int N,B,money[20],d,c,v;
bool xd;
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    while(cin >> B >> N && (B+N)){
        xd=true;
        for(int i=0;i<B;i++){
            cin >> money[i];
        }
        while(N--){
            cin >> d >> c >> v;
            money[--d]-=v;
            money[--c]+=v;
        }
        for(int i=0;i<B;i++){
            if(money[i]<0){
                xd=false;
            }
        }
        if(xd){
            cout << "S\n";
        }else{
            cout << "N\n";
        }
    }
}