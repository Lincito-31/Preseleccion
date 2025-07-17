#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#define ALL(x) x.begin(),x.end()
#define REV(x) x.rbegin(),x.rend()
using namespace __gnu_pbds;
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef vector<long long> vll;
typedef tree<int,null_type,less<int>,rb_tree_tag,tree_order_statistics_node_update> intset;
typedef pair<int,int> pii;
typedef pair<long long,long long> pll;
int t,n,s,mini,maxi,a;
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin >> t;
    while(t--){
        cin >> n >> s;
        mini=1e9;
        maxi=0;
        while(n--){
            cin >> a;
            mini=min(mini,a);
            maxi=max(maxi,a);
        }
        if(s>=maxi){
            cout << s-mini << '\n';
        }else if(s<=mini){
            cout << maxi-s << '\n';
        }else{
            cout << s-mini+maxi-s+min(s-mini,maxi-s) << '\n';
        }
    }
}