#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int q,n,a;
int main(){
    scanf("%d",&q);
    while(q--){
        int c0=0;
        int c1=0;
        int c2=0;
        scanf("%d",&n);
        while(n--){
            scanf("%d",&a);
            a%=3;
            if(a==0){
                c0++;
            }else if(a==1){
                c1++;
            }else{
                c2++;
            }
        }
        int mini=min(c1,c2);
        c1-=mini;c2-=mini;
        c0+=mini;
        c0+=c1/3;
        c0+=c2/3;
        printf("%d\n",c0);
    }
}