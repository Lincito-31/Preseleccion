#include <bits/stdc++.h>
using namespace std;
int a,b;
int main(){
    scanf("%d%d",&a,&b);
    b+=60;
    a-=1;
    b-=45;
    if(b>=60){
        a++;
        b-=60;
    }
    if(a==-1){
        a=23;
    }
    printf("%d %d",a,b);
}