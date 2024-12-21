#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#define MOD 1000000007
#define ALL(x) x.begin(),x.end()
#define REV(x) x.rbegin(),x.rend();
#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
using namespace std;
using namespace __gnu_pbds;
typedef long long ll;
typedef vector<int> vi;
typedef vector<long long> vll;
typedef pair<int,int> pii;
typedef pair<long long,long long> pll;
typedef tree<int,null_type,less<int>,rb_tree_tag,tree_order_statistics_node_update> indexed_set;
int t=1,n;
int main(){
    scanf("%d",&t);
    while(t--){
        scanf("%d",&n);
        vi nums(n);
        vector<bool> visitado(n+1,false);
        for(int i=0;i<n;i++){
            scanf("%d",&nums[i]);
        }
        int j=1;
        vi b(n);
        for(int i=0;i<n;i++){
            if(visitado[nums[i]]){
                while(visitado[j]){
                    j++;
                }
                visitado[j]=true;
                b[i]=j;
            }else{
                b[i]=nums[i];
                visitado[nums[i]]=true;
            }
        }
        for(int i=0;i<n;i++){
            printf("%d ",b[i]);
        }
        printf("\n");
    }
}