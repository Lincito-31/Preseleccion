#include <bits/stdc++.h>
using namespace std;
typedef vector<int> vi;
int n,m,a;
int main(){
    while(scanf("%d%d",&n,&m),n&&m){
        bool xd=false;
        vi exist(n,0);
        int now=0;
        for(int i=1;i<=m;i++){
            scanf("%d",&a);
            if(xd){
                continue;
            }
            now+=a;
            now%=n;
            if(now==0){
                for(int j=1;j<=i;j++){
                    printf("%d ",j);
                }
                printf("\n");
                xd=true;
                continue;
            }
            if(exist[now]){
                for(int j=exist[now]+1;j<=i;j++){
                    printf("%d ",j);
                }
                printf("\n");
                xd=true;
                continue;
            }
            exist[now]=i;
        }
    }
}