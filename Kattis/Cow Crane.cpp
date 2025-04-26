#include <bits/stdc++.h>
#define ALL(x) x.begin(),x.end()
using namespace std;
typedef long long ll;
int m,l,M,L,tl,TM,op1,op2,op3,op4;
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin >> m >> l >> M >> L >> TM >> tl;
    if((abs(m)+abs(M-m)<=TM)&&(abs(m)+abs(M-m)+abs(M-l)+abs(l-L)<=tl)){
        cout << "possible";
        return 0;
    }else if(abs(m)+abs(m-l)+abs(L-l)<=tl && abs(m)+abs(m-l)+abs(L-l)+abs(L-l)+abs(l-M)<=TM){
        cout << "possible";
        return 0;
    }
    swap(m,l);
    swap(M,L);
    swap(tl,TM);
    if((abs(m)+abs(M-m)<=TM)&&(abs(m)+abs(M-m)+abs(M-l)+abs(l-L)<=tl)){
        cout << "possible";
        return 0;
    }else if(abs(m)+abs(m-l)+abs(L-l)<=tl && abs(m)+abs(m-l)+abs(L-l)+abs(L-l)+abs(l-M)<=TM){
        cout << "possible";
        return 0;
    }
    cout << "impossible";
}