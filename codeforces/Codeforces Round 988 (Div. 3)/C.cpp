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
        if(n<=4){
            printf("-1");
        }else{
            for(int i=1;i<=n;i+=2){
                if(i==5){
                    continue;
                }
                printf("%d ",i);
            }
            printf("5 4 ");
            for(int i=2;i<=n;i+=2){
                if(i==4){
                    continue;
                }
                printf("%d ",i);
            }
        }
        printf("\n");
    }
}