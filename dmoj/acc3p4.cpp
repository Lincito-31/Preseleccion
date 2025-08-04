#include <bits/stdc++.h>
#define LsOne(x) (x)&(-x)
using namespace std;
typedef long long ll;
struct BIT{
    vector<ll> fewnwick;
    int tam;
    void add(int x,ll val){
        while(x<=tam){
            fewnwick[x]+=val;
            x+=LsOne(x);
        }
    }
    ll sum(int x){
        ll suma=0;
        while(x>0){
            suma+=fewnwick[x];
            x-=LsOne(x);
        }
        return suma;
    }
    BIT(int n){
        tam=n+2;
        fewnwick.resize(tam);
    }
};
ll t,n,q,tipo,a,b,c;
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
        cin >> n >> q;
        BIT PURQ(n),RUPQ(n);
        while(q--){
            cin >> tipo;
            if(tipo==1){
                cin >> a >> b >> c;
                RUPQ.add(a,c);
                RUPQ.add(b+1,-c);
                PURQ.add(a,c*(a-1));
                PURQ.add(b+1,-c*b);
            }else{
                cin >> a >> b;
                ll val1=RUPQ.sum(b)*b-PURQ.sum(b);
                ll val2=RUPQ.sum(a-1)*(a-1)-PURQ.sum(a-1);
                cout << val1-val2 << '\n';
            }
        }
}