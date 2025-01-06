#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef tree<int,null_type,less<int>,rb_tree_tag,tree_order_statistics_node_update> indexed_set;
int n,con=0;
int main(){
    freopen("bphoto.in","r",stdin);
    freopen("bphoto.out","w",stdout);
    scanf("%d",&n);
    vi cows(n),l(n),r(n);
    indexed_set conj1,conj2;
    for(int i=0;i<n;i++){
        scanf("%d",&cows[i]);
        l[i]=i-conj1.order_of_key(cows[i]);
        conj1.insert(cows[i]);
    }
    for(int i=n-1;i>=0;i--){
        r[i]=n-i-1-conj2.order_of_key(cows[i]);
        conj2.insert(cows[i]);
    }
    for(int i=0;i<n;i++){
        if(max(l[i],r[i])>2*min(l[i],r[i])){
            con++;
        }
    }
    printf("%d",con);
}