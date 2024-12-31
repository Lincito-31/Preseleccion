#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;
using namespace std;
#define MOD 1000000007
#define F first
#define S second
#define PB push_back
#define MP make_pair
#define FIN \n
#define REP(i,a,b) for(int i=a;i<b;i++)
#define ALL(x) x.begin(),x.end()
#define LSOne(x) (x)&-(x)
typedef tree<int,null_type,less<int>,rb_tree_tag,tree_order_statistics_node_update> indexed_set;
typedef long long int ll;
typedef long double ld;
typedef unsigned long long ull;
typedef vector<int> vi;
typedef pair<int,int> pii;
typedef vector<long long> vll;
ll n,m,k,a,b;
int main()
{
    vll res;
    scanf("%lld %lld %lld",&n,&m,&k);
    for(ll i=1;i<=m;i++){
        scanf("%lld %lld",&a,&b);
        if(a==0){
            if(b>0){
                res.push_back(i);
                continue;
            }
        }
        a=n/a;
        b*=a;
        if(b>=k){
            res.push_back(i);
        }
    }if(res.empty()){
        printf("-1");
    }else{
        printf("%lld",res[0]);
        for(int i=1;i<res.size();i++){
            printf(" %lld",res[i]);
        }
    }
}