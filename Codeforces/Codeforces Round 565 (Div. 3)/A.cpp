#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int q;
ll x;
int main(){
    scanf("%d",&q);
    while(q--){
        int con=0;
        scanf("%lld",&x);
        while(x%5==0){
            x/=5;
            x*=4;
            con++;
        }
        while(x%3==0){
            x/=3;
            x*=2;
            con++;
        }
        while(x%2==0){
            x/=2;
            con++;
        }
        printf("%d\n",x==1?con:-1);
    }
}