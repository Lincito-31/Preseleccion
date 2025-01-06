#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef tree<pii,null_type,less<pii>,rb_tree_tag,tree_order_statistics_node_update> indexed_set;
int n,q,a,b;
char t;
int main(){
    scanf("%d%d",&n,&q);
    vi sal(n);
    indexed_set conj;
    for(int i=0;i<n;i++){
        scanf("%d",&sal[i]);
        conj.insert({sal[i],i});
    }
    while(q--){
        scanf(" %c%d%d",&t,&a,&b);
        if(t=='!'){
            a--;
            conj.erase({sal[a],a});
            sal[a]=b;
            conj.insert({sal[a],a});
        }else{
            int men=conj.order_of_key(make_pair(a,-1));
            int may=conj.order_of_key(make_pair(b,1e9));
            printf("%d\n",may-men);
        }
    }
}