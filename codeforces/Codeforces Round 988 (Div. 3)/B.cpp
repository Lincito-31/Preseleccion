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
typedef tree<int,null_type,less<int>,rb_tree_tag,tree_order_statistics_node_update> indexed_set;

int t=1,n,a;
int main(){
    scanf("%d",&t);
    while(t--){
        scanf("%d",&n);
        map<int,int> gau;
        int con=0;
        for(int i=0;i<n;i++){
            scanf("%d",&a);
            gau[a]++;
        }
        n-=2;
        int x,y;
        for(int i=1;i*i<=n;i++){
            if(i*i==n){
                if(gau[i]>=2){
                    x=y=i;
                }
            }else{
                if(n%i==0){
                    if(gau[i]>=1 && gau[n/i]>=1){
                        x=i;y=n/i;
                        break;
                    }
                }
            }
        }
        printf("%d %d\n",x,y);
    }
}