#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#define ALL(x) x.begin(),x.end()
#define REV(x) x.rbegin(),x.rend()
#define MOD 1000000007
using namespace std;
using namespace __gnu_pbds;
typedef long long ll;
typedef vector<int> vi;
typedef vector<long long> vll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
typedef tree<int,null_type,less<int>,rb_tree_tag,tree_order_statistics_node_update> indexed_set;

ll t=1,n,m,l;
int main(){
    scanf("%lld",&t);
    while(t--){
        scanf("%lld%lld%lld",&n,&m,&l);
        vector<pll> hurdles(n);
        vector<pll> powerups(m);
        ll now=1;
        for(int i=0;i<n;i++){
            scanf("%lld%lld",&hurdles[i].first,&hurdles[i].second);
            hurdles[i].first--;
            hurdles[i].second++;
            hurdles[i].second-=hurdles[i].first;
        }
        for(int i=0;i<m;i++){
            scanf("%lld%lld",&powerups[i].first,&powerups[i].second);
        }
        priority_queue<ll> available;
        int j=0;//powerup
        ll con=0;
        bool xd=true;
        bool lol=true;
        for(int i=0;i<n;i++){
            while(xd && powerups[j].first<=hurdles[i].first){
                available.push(powerups[j].second);
                j++;
                if(j>=m){
                    j--;
                    xd=false;
                }
            }
            while(now<hurdles[i].second){
                if(!available.empty()){
                    now+=available.top();
                    available.pop();
                    con++;
                }else{
                    lol=false;
                    break;
                }
            }
            if(!lol){
                break;
            }
        }
        if(!lol){
            printf("-1\n");
        }else{
            printf("%lld\n",con);
        }
    }
}