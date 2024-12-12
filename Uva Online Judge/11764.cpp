#include <bits/stdc++.h>
using namespace std;
int t,n,a,b;
int main(){
    scanf("%d",&t);
    for(int i=1;i<=t;i++){
        int h=0,l=0;
        scanf("%d",&n);
        scanf("%d",&a);
        while(--n){
            scanf("%d",&b);
            if(b>a){
                h++;
            }else if(b<a){
                l++;
            }
            a=b;
        }
        printf("Case %d: %d %d\n",i,h,l);
    }
}