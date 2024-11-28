#include <bits/stdc++.h>
using namespace std;
int a,b;
int main(){
    scanf("%d%d",&a,&b);
    if(a==0&&b==0){
        printf("Not a moose");
    }else{
        if(a==b){
            printf("Even %d",a+b);
        }else{
            printf("Odd %d",2*max(a,b));
        }
    }
}