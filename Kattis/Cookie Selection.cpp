#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#define ALL(x) x.begin(),x.end()
#define REV(x) x.rbegin(),x.rend()
using namespace std;
using namespace __gnu_pbds;
typedef long long ll;
typedef tree<int,null_type,less_equal<int>,rb_tree_tag,tree_order_statistics_node_update> intset;
string x;
int b;
intset s;
stringstream a;
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    while(cin >> x){
        if(x=="#"){
            auto p=s.find_by_order(s.size()/2);
            cout << *p << '\n';
            s.erase(p);
        }else{
            a=stringstream(x);
            a>>b;
            s.insert(b);
        }
    }
}