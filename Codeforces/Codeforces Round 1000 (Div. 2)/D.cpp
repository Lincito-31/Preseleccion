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
typedef tree<ll,null_type,less<ll>,rb_tree_tag,tree_order_statistics_node_update> llset;
ll t=1,n,m;
int main(){
    scanf("%lld",&t);
    while(t--){
        scanf("%lld%lld",&n,&m);
        vll a(n),b(m),resa(n),resb(m);
        for(int i=0;i<n;i++){
            scanf("%lld",&a[i]);
        }
        for(int i=0;i<m;i++){
            scanf("%lld",&b[i]);
        }
        sort(ALL(a));
        sort(ALL(b));
        for(int i=0;i<n;i++){
            if(n-i-1<=i){
                break;
            }
            resa[i]=abs(a[n-i-1]-a[i]);
        }
        for(int i=0;i<m;i++){
            if(m-i-1<=i){
                break;
            }
            resb[i]=abs(b[m-i-1]-b[i]);
            //cout << b[m-i+1] << " " << b[i-1] << endl;
        }
        ll sum=0,k=0;
        
    }
}
