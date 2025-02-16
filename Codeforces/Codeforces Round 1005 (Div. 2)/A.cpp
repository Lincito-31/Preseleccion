#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#define MOD 1000000007
#define ALL(x) x.begin(),x.end()
#define REV(x) x.rbegin(),x.rend()
#define FASTIO ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr)
using namespace __gnu_pbds;
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef vector<long long> vll;
typedef pair<int,int> pii;
typedef pair<long long,long long> pll;
typedef tree<int,null_type,less_equal<int>,rb_tree_tag,tree_order_statistics_node_update> intset;
int t=1,n;
string x;
int main(){
    FASTIO;
    cin >> t;
    while(t--){
        cin >> n;
        cin >> x;
        int con=0;
        bool xd=false;
        for(int i=0;i<n;i++){
            if(!xd && x[i]=='1'){
                xd=true;
                con++;
            }else if(xd && x[i]=='0'){
                xd=false;
                con++;
            }
        }
        cout << con << "\n";
    }
}
