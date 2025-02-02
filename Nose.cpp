#include <bits/stdc++.h>
using namespace std;
#include <bits/extc++.h>
using namespace __gnu_pbds;
typedef long long ll;
typedef pair<ll,ll> pll;
typedef tree<ll,null_type,less_equal<ll>,rb_tree_tag,tree_order_statistics_node_update> llset;

int main(){
    llset a;
    a.insert(7);
    a.insert(4);
    cout << a.order_of_key(0);
}
