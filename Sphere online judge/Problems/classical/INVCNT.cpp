#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;
using namespace std;
typedef long long ll;
typedef tree<int,null_type,less<int>,rb_tree_tag,tree_order_statistics_node_update> indexed_set;
ll t,n,a;
int main(){
    cin >> t;
    while(t--){
        ll can=0;
        indexed_set conjunto;
        cin >> n;
        while(n--){
            cin >> a;
            can+=(ll)(conjunto.size()-conjunto.order_of_key(a));
            conjunto.insert(a);
        }
        cout << can << '\n';
    }
}
