#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int t,x,y,z;
int main(){
    scanf("%d",&t);
    for(int i=1;i<=t;i++){
        scanf("%d%d%d",&x,&y,&z);
        printf("Case %d: ",i);
        if(x<=20 && y<=20 && z<=20){
            printf("good");
        }else{
            printf("bad");
        }
        printf("\n");
    }
}