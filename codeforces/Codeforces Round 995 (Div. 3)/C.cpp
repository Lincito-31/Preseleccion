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
int t=1,n,m,k,x;
int main(){
    scanf("%d",&t);
    while(t--){
        scanf("%d%d%d",&n,&m,&k);
        if(k<n-1){
            for(int i=0;i<m;i++){
                scanf("%d",&x);
            }
            for(int i=0;i<k;i++){
                scanf("%d",&x);
            }
            for(int i=0;i<m;i++){
                printf("0");
            }
            printf("\n");
            continue;
        }else if(k==n){
            for(int i=0;i<m;i++){
                scanf("%d",&x);
            }
            for(int i=0;i<k;i++){
                scanf("%d",&x);
            }
            for(int i=0;i<m;i++){
                printf("1");
            }
            printf("\n");
            continue;
        }else{
            vi list(m);
            for(int i=0;i<m;i++){
                scanf("%d",&list[i]);
            }
            vector<bool> know(n+1,false);
            for(int i=0;i<k;i++){
                scanf("%d",&x);
                know[x]=true;
            }
            for(int i=0;i<m;i++){
                if(know[list[i]]){
                    printf("0");
                }else{
                    printf("1");
                }
            }
            printf("\n");
        }
    }
}