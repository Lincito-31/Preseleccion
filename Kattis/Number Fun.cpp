#include <bits/stdc++.h>
using namespace std;
double a,b,c;
int n;
int main(){
    scanf("%d",&n);
    while(n--){
        scanf("%lf%lf%lf",&a,&b,&c);
        if(a+b==c || a*b==c || a/b==c || b/a==c || abs(a-b)==c){
            printf("Possible\n");
        }else{
            printf("Impossible\n");
        }
    }
}