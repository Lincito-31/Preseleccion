#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;
using namespace std;
typedef long long ll;
typedef tree<int,null_type,less<int>,rb_tree_tag,tree_order_statistics_node_update> indexed_set;
int t,a;
char c;
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin >> t;
    indexed_set sol;
    while(t--){
        cin >> c >> a;
        if(c=='I'){
            sol.insert(a);
        }else if(c=='D'){
            sol.erase(a);
        }else if(c=='K'){
            if(sol.size()<a--){
                cout << "invalid\n";
            }else{
                cout << *sol.find_by_order(a) << '\n';
            }
        }else{
            cout << sol.order_of_key(a) << '\n';
        }
    }
}
