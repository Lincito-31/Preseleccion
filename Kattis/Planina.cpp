#include <bits/stdc++.h>
using namespace std;
int x;
int main(){
    scanf("%d",&x);
    x++;
    x=pow(2,x-1);
    x=4*x*x-4*(x-1)-3*(x-1)*(x-1);
    printf("%d",x);
}