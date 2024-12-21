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
        int con=0;
        scanf("%d",&n);
        for(int i=1;i<n;i++){
            for(int j=1;j<n;j++){
                if(i+j==n){
                    con++;
                }
            }
        }
        printf("%d\n",con);
    }
}