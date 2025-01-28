#include <bits/stdc++.h>
using namespace std;
int n;
void solve(int x){
    bool xd=false;
    for(int i=30;i>=0;i--){
        if(x&(1<<i)){
            if(xd){
                printf("+");
            }
            xd=true;
            if(i==0){
                printf("2(0)");
            }else if(i==1){
                printf("2");
            }else if(i==2){
                printf("2(2)");
            }else{
                printf("2(");
                solve(i);
                printf(")");
            }
        }
    }
}
int main(){
    scanf("%d",&n);
    solve(n);
}