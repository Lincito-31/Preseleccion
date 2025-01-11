#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;
using namespace std;
typedef tree<int,null_type,less<int>,rb_tree_tag,tree_order_statistics_node_update> intset;
int t,n,m;
bool xd1=false;
int main(){
    scanf("%d",&t);
    while(t--){
        intset x;
        scanf("%d%d",&n,&m);
        int repre[n+1],con=0;
        while(n--){
            repre[n+1]=n+1;
            x.insert(n+1);
        }
        xd1=false;
        while(m--){
            scanf("%d",&n);
            if(xd1){
                printf(" ");
            }
            xd1=true;
            printf("%d",x.order_of_key(repre[n]));
            x.erase(repre[n]);
            repre[n]=con--;
            x.insert(repre[n]);
        }
        printf("\n");
    }
}