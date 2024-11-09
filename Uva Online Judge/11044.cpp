#include <bits/stdc++.h>
using namespace std;
int t,a,b;
int main(){
    scanf("%d",&t);
    while(t--){
        scanf("%d%d",&a,&b);
        a-=2;b-=2;
        a=(a-1)/3;
        a++;
        b=(b-1)/3;
        b++;
        printf("%d\n",a*b);
    }
}