#include <bits/stdc++.h>
using namespace std;
int a,b;
int main(){
    while(scanf("%d%d",&a,&b),a||b){
        int A[a],B[b];
        for(int i=0;i<a;i++){
            scanf("%d",&A[i]);
        }
        for(int i=0;i<b;i++){
            scanf("%d",&B[i]);
        }
        int j=0,con=0;
        for(int i=0;i<a;i++){
            if(j<b){
                if(A[i]==B[j]){
                    con++;
                    j++;
                }else if(A[i]>B[j]){
                    j++;i--;
                }
            }
        }
        printf("%d\n",con);
    }
}