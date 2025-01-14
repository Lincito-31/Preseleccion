#include <bits/stdc++.h>
using namespace std;
int t,res;
int main(){
    scanf("%d",&t);
    while(t--){
        int l=2,r=999;
        while(l<r){
            int tercia=(r-l)/3;
            int num1=l+tercia;
            int num2=r-tercia;
            printf("? %d %d\n",num1,num2);
            fflush(stdout);
            scanf("%d",&res);
            if(res==(num1+1)*(num2+1)){
                //esta izquierdo
                r=num1;
            }else if(res==num1*(num2+1)){
                //esta medio
                l=num1+1;
                r=num2;
            }else{
                //esta derecho
                l=num2+1;
            }
        }
        printf("! %d\n",l);
        fflush(stdout);
    }
}