#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll H,W,M,t,a,b,tot=0,con=0,HH,WW;
int main(){
    scanf("%lld%lld%lld",&H,&W,&M);
    HH=H;
    WW=W;
    set<ll> row;
    set<ll> col;
    vector<vector<ll>> ope(M);
    vector<ll> cont(2e5+5,0);
    for(int i=0;i<M;i++){
        scanf("%lld%lld%lld",&t,&a,&b);
        ope[i]={t,a,b};
    }
    for(int i=M-1;i>=0;i--){
        if(ope[i][0]==1){
            if(W>0 && row.find(ope[i][1])==row.end()){
                cont[ope[i][2]]+=W;
                H--;
                row.insert(ope[i][1]);
            }
        }else{
            if(H>0 && col.find(ope[i][1])==col.end()){
                cont[ope[i][2]]+=H;
                W--;
                col.insert(ope[i][1]);
            }
        }
    }
    for(int i=1;i<=2e5;i++){
        if(cont[i]){
            con++;
            tot+=cont[i];
        }
    }
    ll zero=WW*HH-tot;
    if(zero>0){
        con++;
        cont[0]=zero;
    }
    printf("%lld\n",con);
    for(int i=0;i<=2e5;i++){
        if(cont[i]){
            printf("%lld %lld\n",i,cont[i]);
        }
    }
}