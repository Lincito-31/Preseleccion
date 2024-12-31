#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;
using namespace std;
#define MOD 1000000007
#define F first
#define S second
#define PB push_back
#define MP make_pair
#define FIN "\n"
#define REP(i,a,b) for(int i=a;i<b;i++)
#define ALL(x) x.begin(),x.end()
#define LSOne(x) (x)&-(x)
#define FASTIO ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define beginzeros(x) __builtin_clz(x)
#define endzeros(x) __builtin_ctz(x)
#define countones(x) __builtin_popcount(x)
#define parity(x) __builtin_parity(x)
typedef tree<int,null_type,less<int>,rb_tree_tag,tree_order_statistics_node_update> indexed_set;
typedef long long int ll;
typedef long double ld;
typedef unsigned long long ull;
typedef vector<int> vi;
typedef pair<int,int> pii;
typedef vector<long long> vll;
int n;
ll a,c;
int main()
{
    scanf("%d",&n);
    while(n--){
        scanf("%lld %lld",&a,&c);
        if(c>a){
            printf("-1\n");
        }else{
            ll x=a/c;
            if(a/x==c){
                printf("%lld\n",a);
            }else{
                printf("-1\n");
            }
        }
    }
}