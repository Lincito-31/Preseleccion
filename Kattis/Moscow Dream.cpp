#include <bits/stdc++.h>
using namespace std;
int a,b,c,n;
int main(){
    scanf("%d%d%d%d",&a,&b,&c,&n);
    if(a>0&&b>0&&c>0&&(a+b+c)>=n && n>2){
        printf("YES");
    }else{
        printf("NO");
    }
}