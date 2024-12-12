#include <bits/stdc++.h>
using namespace std;
int a,b,c,n;
int main(){
    scanf("%d",&n);
    while(n--){
        scanf("%d%d%d",&a,&b,&c);
        b-=c;
        if(b>a){
            printf("advertise\n");
        }else if(b==a){
            printf("does not matter\n");
        }else{
            printf("do not advertise\n");
        }
    }
}