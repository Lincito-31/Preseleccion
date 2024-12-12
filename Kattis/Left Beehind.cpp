#include <bits/stdc++.h>
using namespace std;
int a,b;
int main(){
    while(scanf("%d%d",&a,&b),a||b){
        if(a+b==13){
            printf("Never speak again.\n");
        }else if(a>b){
            printf("To the convention.\n");
        }else if(a<b){
            printf("Left beehind.\n");
        }else{
            printf("Undecided.\n");
        }
    }
}