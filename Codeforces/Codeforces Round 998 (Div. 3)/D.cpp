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
int t=1,n;
int main(){
    scanf("%d",&t);
    while(t--){
        scanf("%d",&n);
        vector<int> nums(n);
        for(int i=0;i<n;i++){
            scanf("%d",&nums[i]);
        }
        bool xd=true;
        for(int i=1;i<n;i++){
            int temp=min(nums[i],nums[i-1]);
            nums[i]-=temp;
            nums[i-1]-=temp;
            if(nums[i-1]>0){
                xd=false;
                break;
            }
        }
        if(xd){
            printf("YES\n");
        }else{
            printf("NO\n");
        }
    }
}
