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
int t,n,a;
int main(){
    scanf("%d",&t);
    while(t--){
        scanf("%d",&n);
        ll sump=0;
        ll sumi=0;
        for(int i=0;i<n;i++){
            scanf("%d",&a);
            if(i%2==0){
                sump+=a;
            }else{
                sumi+=a;
            }
        }
        ll canp=0,cani=0;
        canp=(n+1)/2;
        cani=n/2;
        if(sump%canp==0 && sumi%cani==0 && sump/canp==sumi/cani){
            printf("YES\n");
        }else{
            printf("NO\n");
        }
    }
}