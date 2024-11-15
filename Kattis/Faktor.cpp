#include <bits/stdc++.h>
using namespace std;
int n,p;
int main(){
    scanf("%d%d",&n,&p);
    p*=n;
    p-=n;
    p++;
    printf("%d",p);
}