#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#define ALL(x) x.begin(),x.end()
#define REV(x) x.rbegin(),x.rend()
using namespace std;
using namespace __gnu_pbds;
typedef long long ll;
typedef tree<int,null_type,less_equal<int>,rb_tree_tag,tree_order_statistics_node_update> intset;
string t,x;
int n;
map<string,bool> door;
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin >> n;
    while(n--){
        cin >> t >> x;
        if(t=="entry"){
            cout << x << " entered";
            if(door[x]){
                cout << " (ANOMALY)";
            }
            door[x]=true;
        }else{
            cout << x << " exited";
            if(!door[x]){
                cout << " (ANOMALY)";
            }
            door[x]=false;
        }
        cout << '\n';
    }
}