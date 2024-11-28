#include <bits/stdc++.h>
using namespace std;
int t,x;
int main(){
    scanf("%d",&t);
    while(t--){
        scanf("%d",&x);
        if(x%2==0){
            printf("%d is even\n",x);
        }else{
            printf("%d is odd\n",x);
        }
    }
}