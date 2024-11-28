#include <bits/stdc++.h>
using namespace std;
double x,y;
int main(){
    scanf("%lf%lf",&x,&y);
    if(y==1){
        if(x==0){
            printf("ALL GOOD");
        }else{
            printf("IMPOSSIBLE");
        }
    }else{
        double k=x/(y-1);
        printf("%.6lf",-k);
    }
}