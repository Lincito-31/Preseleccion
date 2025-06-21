#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#define ALL(x) x.begin(),x.end()
#define REV(x) x.rbegin(),x.rend()
using namespace std;
using namespace __gnu_pbds;
typedef long long ll;
typedef tree<int,null_type,less_equal<int>,rb_tree_tag,tree_order_statistics_node_update> intset;
string x,b;
unordered_map<string,string> dic;
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    while(getline(cin,x) && !x.empty()){
        stringstream a(x);
        a >> b >> x;
        dic[x]=b;
    }
    while(cin >> x){
        if(dic.count(x)){
            cout << dic[x] << '\n';
        }else{
            cout << "eh\n";
        }
    }
}