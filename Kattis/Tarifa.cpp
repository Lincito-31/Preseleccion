#include <bits/stdc++.h>
using namespace std;
int n,x,a;
int main(){
    scanf("%d",&x);
    scanf("%d",&n);
    x*=(n+1);
    while(n--){
        scanf("%d",&a);
        x-=a;
    }
    printf("%d",x);
}