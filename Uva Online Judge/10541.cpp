#include <bits/stdc++.h>
using namespace std;
int t,n,k,a;
int main(){
    scanf("%d",&t);
    while(t--){
        scanf("%d%d",&n,&k);
        int blank=n;
        for(int i=0;i<k;i++){
            scanf("%d",&a);
            blank-=a;
        }
        blank-=k-1;
        if(blank<0){
            printf("0\n");
        }else{
            //tengo k+k-1 espacios fijos;
            //tengo que poner blank espacios blancos entre ellos;
            // hay entotal k+k-1+blank espacios;
            // tnego que elegir blank;
            
        }
    }
}