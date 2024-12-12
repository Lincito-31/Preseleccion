#include <bits/stdc++.h>
using namespace std;
int a,b,c;
int main(){
    while(scanf("%d%d%d",&a,&b,&c)!=EOF){
        c-=a;
        if(b>c){
            printf("Hunters win!\n");
        }else{
            printf("Props win!\n");
        }
    }
}