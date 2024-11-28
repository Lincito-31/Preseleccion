#include <bits/stdc++.h>
using namespace std;
int a,b;
int main(){
    scanf("%d%d",&a,&b);
    b-=a;
    if(b>0){
        if(b==1){
            printf("Dr. Chaz will have 1 piece of chicken left over!");
        }else{
            printf("Dr. Chaz will have %d pieces of chicken left over!",b);
        }
    }else{
        b*=-1;
        if(b==1){
            printf("Dr. Chaz needs 1 more piece of chicken!");
        }else{
            printf("Dr. Chaz needs %d more pieces of chicken!",b);
        }
    }
}