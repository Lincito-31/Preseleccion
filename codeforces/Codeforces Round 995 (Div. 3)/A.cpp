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
int t=1,n;
int main(){
    scanf("%d",&t);
    while(t--){
        scanf("%d",&n);
        vi a(n),b(n);
        for(int i=0;i<n;i++){
            scanf("%d",&a[i]);
        }
        for(int i=0;i<n;i++){
            scanf("%d",&b[i]);
        }
        int sum=a.back();
        for(int i=0;i<n-1;i++){
            if(a[i]>b[i+1]){
                sum+=a[i]-b[i+1];
            }
        }
        printf("%d\n",sum);
    }
}