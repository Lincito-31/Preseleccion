#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#define MOD 1000000007
#define ALL(x) x.begin(),x.end()
#define REV(x) x.rbegin(),x.rend()
#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
using namespace __gnu_pbds;
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef vector<long long> vll;
typedef pair<int,int> pii;
typedef pair<long long,long long> pll;
typedef tree<int,null_type,less_equal<int>,rb_tree_tag,tree_order_statistics_node_update> intset;
int t=1,n,a;
int main(){
    FASTIO;
    cin >> t;
    while(t--){
        cin >> n;
        set<int> x,y;
        for(int i=0;i<n;i++){
            cin >> a;
            x.insert(a);
        }
        for(int i=0;i<n;i++){
            cin >> a;
            y.insert(a);
        }
        if(x.size()>=3 || y.size()>=3){
            cout << "YES\n";
        }else if(x.size()>=2 && y.size()>=2){
            cout << "YES\n";
        }else{
            cout << "NO\n";
        }
    }
}
