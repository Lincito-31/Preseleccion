#include <bits/stdc++.h>
#define MOD 998244353
using namespace std;
int q,k,a;
char c;
int res[5001];
int main(){
    scanf("%d%d",&q,&k);
    for(int i=0;i<=5000;i++){
        res[i]=0;
    }
    res[0]=1;
    while(q--){
        scanf(" %c %d",&c,&a);
        if(c=='+'){
            for(int i=5000;i>=0;i--){
                if(res[i]==0 || i+a>5000){
                    continue;
                }
                res[i+a]+=res[i];
                res[i+a]%=MOD;
            }
        }else{
            for(int i=0;i<=5000;i++){
                if(res[i]==0){
                    continue;
                }
                if(i-a<0){
                    continue;
                }
                res[i]-=res[i-a];
                res[i]%=MOD;
                res[i]+=MOD;
                res[i]%=MOD;
            }
        }
        printf("%d\n",res[k]);
    }
}