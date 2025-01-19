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
int t=1,n,m,a;
int main(){
    scanf("%d",&t);
    while(t--){
        scanf("%d%d",&n,&m);
        vector<int> ord(n);
        bool xd=true;
        for(int i=0;i<n;i++){
            scanf("%d",&a);
            int res=0;
            res=a%n;
            ord[res]=i;
            for(int j=1;j<m;j++){
                scanf("%d",&a);
                if(a%n!=res){
                    xd=false;
                }
            }
        }
        if(xd){
            for(int i=0;i<n;i++){
                printf("%d ",ord[i]+1);
            }
            printf("\n");
        }else{
            printf("-1\n");
        }
    }
}
