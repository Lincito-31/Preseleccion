#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int a,b;
int main(){
    int con=1;
    while(true){
        scanf("%d%d",&a,&b);
        if(!(a||b)){
            break;
        }
        printf("Case %d: ",con++);
        if(b==0){
            printf("impossible\n");
            continue;
        }
        a-=b;
        if(a<=0){
            printf("0\n");
            continue;
        }
        a--;
        a/=b;
        a++;
        if(a>26){
            printf("impossible\n");
        }else{
            printf("%d\n",a);
        }
    }
}