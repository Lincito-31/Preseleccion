#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#define ALL(x) x.begin(),x.end()
#define REV(x) x.rbegin(),x.rend()
using namespace __gnu_pbds;
using namespace std;
typedef tree<int,null_type,less<int>,rb_tree_tag,tree_order_statistics_node_update> indexed_set;
typedef long long ll;
typedef vector<int> vi;
typedef vector<long long> vll;
typedef pair<int,int> pii;
ll t=1,n,b,c;
int main(){
    scanf("%lld",&t);
    while(t--){
        scanf("%lld%lld%lld",&n,&b,&c);
        if(b>0){
            ll x=n-c;
            if(x<=0){
                printf("%lld\n",n);
                continue;
            }
            if(x%b==0){
                x/=b;
                x--;
            }else{
                x/=b;
            }
            x++;
            printf("%lld",n-x);
        }else{
            if(c>=n){
                printf("%lld",n);
            }else{
                if(c==n-2 || c==n-1){
                    printf("%lld",n-1);
                }else{
                    printf("-1");
                }
            }
        }
        printf("\n");
    }
}