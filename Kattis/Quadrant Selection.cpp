#include <bits/stdc++.h>
using namespace std;
int x,y;
int main(){
    scanf("%d%d",&x,&y);
    if(x>0){
        if(y>0){
            printf("1");
        }else{
            printf("4");
        }
    }else{
        if(y>0){
            printf("2");
        }else{
            printf("3");
        }
    }
}