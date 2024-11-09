#include <bits/stdc++.h>
using namespace std;
int t,a;
int main(){
    scanf("%d",&t);
    while(t--){
        scanf("%d",&a);
        a*=315;
        a+=36962;
        a=abs(a);
        a/=10;
        a%=10;
        printf("%d\n",a);
    }
}