#include <bits/stdc++.h>
using namespace std;
int t,n,m,cont,a;
int main(){
    scanf("%d",&t);
    while(t--){
        scanf("%d%d",&n,&m);
        map<int,int> con;
        cont=0;
        while(n--){
            scanf("%d",&a);
            con[a]++;
        }
        while(m--){
            scanf("%d",&a);
            con[a]--;
        }
        for(auto u:con){
            cont+=abs(u.second);
        }
        printf("%d\n",cont);
    }
}