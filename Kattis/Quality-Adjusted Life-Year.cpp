#include <bits/stdc++.h>
using namespace std;
int t;
float x,y,sum=0;
int main(){
    scanf("%d",&t);
    while(t--){
        scanf("%f%f",&x,&y);
        sum+=x*y;
    }
    printf("%.3f",sum);
}