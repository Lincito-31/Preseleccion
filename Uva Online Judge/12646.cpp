#include <bits/stdc++.h>
using namespace std;
int a,b,c;
int main(){
    while(scanf("%d%d%d",&a,&b,&c)!=EOF){
        if(a!=b && a!=c){
            printf("A\n");
        }else if(b!=a && b!=c){
            printf("B\n");
        }else if(c!=a && c!=b){
            printf("C\n");
        }else{
            printf("*\n");
        }
    }
}