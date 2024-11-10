#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int t,c,a,b;
int main(){
    scanf("%d",&t);
    for(int i=1;i<=t;i++){
        scanf("%d%d%d",&a,&b,&c);
        printf("Case %d: %d\n",i,a+b+c-max({a,b,c})-min({a,b,c}));
    }
}