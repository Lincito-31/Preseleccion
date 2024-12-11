#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#define ALL(x) x.begin(),x.end()
#define REV(x) x.rbegin(),x.rend()
#define MOD 1000000007
#define FASTIO ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
using namespace __gnu_pbds;
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef vector<long long> vll;
typedef pair<int,int> pii;
typedef pair<long long,long long> pll;
typedef tree<int,null_type,less<int>,rb_tree_tag,tree_order_statistics_node_update> indexed_set;
int t=1,n,k;
int main(){
    scanf("%d",&t);
    while(t--){
        scanf("%d%d",&n,&k);
        vi nums(n);
        for(int i=0;i<n;i++){
            scanf("%d",&nums[i]);
        }
        bool xd=true;
        for(int i=0;i<n;i++){
            xd=true;
            for(int j=0;j<n;j++){
                if(i==j){
                    continue;
                }
                if(abs(nums[i]-nums[j])%k==0){
                    xd=false;
                    break;
                }
            }
            if(xd){
                printf("YES\n%d\n",i+1);
                break;
            }
        }
        if(!xd){
            printf("NO\n");
        }
    }
}