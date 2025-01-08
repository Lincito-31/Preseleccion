#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;
using namespace std;
typedef pair<int,int> pii;
typedef tree<pii,null_type,less<pii>,rb_tree_tag,tree_order_statistics_node_update> piiset;
int t,n,m,a;
int main(){
    scanf("%d",&t);
    while(t--){
        scanf("%d%d",&n,&m);
        piiset x;
        int con=0;
        for(int i=0;i<n;i++){
            
        }
        while(m--){
            scanf("%d",&a);
            auto p=x.lower_bound({a,-1e9});
            printf("%d ",x.order_of_key(make_pair(p->first,p->second)));
            x.erase(p);
            x.insert({con,a});
            con--;
        }
        printf("\n");
    }
}