#include <bits/stdc++.h>
using namespace std;
int x,y,z;
int main(){
    scanf("%d%d%d",&x,&y,&z);
    int sum=3*x+2*y+z;
    if(sum>=8){
        printf("Province or ");
    }else if(sum>=5){
        printf("Duchy or ");
    }else if(sum>=2){
        printf("Estate or ");
    }
    if(sum>=6){
        printf("Gold");
    }else if(sum>=3){
        printf("Silver");
    }else{
        printf("Copper");
    }
}