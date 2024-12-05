#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#define ALL(x) x.begin(),x.end()
#define REV(x) x.rbegin(),x.rend()
#define MOD 1000000007
using namespace __gnu_pbds;
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef vector<long long> vll;
typedef pair<int,int> pii;
typedef pair<long long,long long> pll;
typedef tree<int,null_type,less<int>,rb_tree_tag,tree_order_statistics_node_update> indexed_set;
int t,n,m;
string st;
int main(){
    cin >> t;
    while(t--){
        cin >> n >> m;
        int c=0;
        bool xd=true;
        while(n--){
            cin >> st;
            if(m>=st.size()&&xd){
                m-=st.size();
                c++;
            }else{
                xd=false;
            }
        }
        cout << c << "\n";
    }
}