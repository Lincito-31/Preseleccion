#include <bits/stdc++.h>
using namespace std;
float n;
int main(){
    scanf("%f",&n);
    n*=1000;
    n*=5280;
    n/=4854;
    n+=0.5;
    int x=int(n);
    printf("%d",x);
}