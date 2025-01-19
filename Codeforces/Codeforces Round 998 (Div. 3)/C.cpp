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
typedef tree<int,null_type,less<int>,rb_tree_tag,tree_order_statistics_node_update> intset;
int t=1,n,k,a;
int main(){
    scanf("%d",&t);
    while(t--){
        scanf("%d%d",&n,&k);
        vi cont(3*n+5,0);
        for(int i=0;i<n;i++){
            scanf("%d",&a);
            cont[a]++;
        }
        int res=0;
        for(int i=1;i<=n;i++){
            if(k-i<0){
                continue;
            }
            if(k-i==i){
                res+=cont[i]/2;
            }else{
                int temp=min(cont[i],cont[k-i]);
                res+=temp;
                cont[i]-=temp;
                cont[k-i]-=temp;
            }
        }
        printf("%d\n",res);
    }
}
