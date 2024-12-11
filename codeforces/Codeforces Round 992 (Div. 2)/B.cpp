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
int t=1,n,i=1;
int main(){
    scanf("%d",&t);
    vi res(1e5+5,-1);
    res[1]=1;
    int j=0;
    while(j<1e5+5){
        for(j=i+1;j<=2*(i+1) && j<1e5+5;j++){
            res[j]=res[i]+1;
        }
        i=2*(i+1);
    }
    while(t--){
        scanf("%d",&n);
        printf("%d\n",res[n]);
    }
}