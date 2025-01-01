#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;
using namespace std;
typedef long long ll;
typedef tree<int,null_type,less<int>,rb_tree_tag,tree_order_statistics_node_update> indexed_set;
int t,n,a;
int main(){
    scanf("%d",&t);
    while(t--){
        ll can=0;
        indexed_set conjunto;
        scanf("%d",&n);
        while(n--){
            scanf("%lld",&a);
            can+=conjunto.size()-conjunto.order_of_key(a);
            conjunto.insert(a);
        }
        printf("%lld\n",can);
    }
}
