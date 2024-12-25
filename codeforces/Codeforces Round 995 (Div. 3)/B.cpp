#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#define MOD 1000000007
#define ALL(x) x.begin(),x.end();
#define REV(x) x.rbegin(),x.rend();
using namespace std;
using namespace __gnu_pbds;
typedef long long ll;
typedef vector<int> vi;
typedef vector<long long> vll;
typedef pair<int,int> pii;
typedef pair<long long,long long> pll;
typedef tree<int,null_type,less<int>,rb_tree_tag,tree_order_statistics_node_update> indexed_set;
ll t=1,n,a,b,c;
int main(){
    scanf("%lld",&t);
    while(t--){
        scanf("%lld%lld%lld%lld",&n,&a,&b,&c);
        ll sum=a+b+c;
        ll day=n/sum;
        day*=3;
        n%=sum;
        if(n>0){
            n-=a;
            day++;
            if(n>0){
                day++;
                n-=b;
                if(n>0){
                    day++;
                }
            }
        }
        printf("%d\n",day);
    }
}