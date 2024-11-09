#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int t,n,k,p;
int main(){
    scanf("%d",&t);
    for(int i=1;i<=t;i++){
        scanf("%d%d%d",&n,&k,&p);
        k+=p;
        k%=n;
        if(k==0){
            k=n;
        }
        printf("Case %d: %d\n",i,k);
    }
}