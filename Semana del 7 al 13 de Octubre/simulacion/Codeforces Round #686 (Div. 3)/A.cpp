#include <bits/stdc++.h>
using namespace std;
int n,a;
int main(){
    scanf("%d",&n);
    while(n--){
        scanf("%d",&a);
        printf("%d ",a);
        for(int i=1;i<a;i++){
            printf("%d ",i);
        }
        printf("\n");
    }
}