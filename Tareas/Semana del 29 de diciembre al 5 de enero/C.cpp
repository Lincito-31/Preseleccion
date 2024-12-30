#include <bits/stdc++.h>
#define MOD 998244353
using namespace std;
int q,k,a;
char c;
map<int,int> mapa;
int main(){
    mapa[0]=1;
    scanf("%d%d",&q,&k);
    while(q--){
        scanf(" %c %d",&c,&a);
        if(c=='+'){
            auto p=mapa.end();
            while(p!=mapa.begin()){
                p--;
                if(p->second<=0){
                    continue;
                }
                mapa[p->first+a]+=p->second;
            }
        }else{
            auto p=mapa.end();
            while(p!=mapa.begin()){
                p--;
                if(p->second<=0){
                    continue;
                }
                if(p->first-a>=0){
                    p->second-=mapa[p->first-a];
                    /*if(p->second==0 && p->first!=k){
                        mapa.erase(p->first);
                    }*/
                }
            }
        }
        printf("%d\n",mapa[k]);
    }
}