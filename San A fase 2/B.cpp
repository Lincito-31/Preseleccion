#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#define MOD 1000000007
#define ALL(x) x.begin(),x.end()
#define REV(x) x.rbegin(),x.rend()
using namespace __gnu_pbds;
using namespace std;
typedef tree<int,null_type,less<int>,rb_tree_tag,tree_order_statistics_node_update> indexed_set;
typedef long long ll;
typedef vector<int> vi;
typedef vector<long long> vll;
typedef pair<int,int> pii;
int t,a;
int main(){
    vector<vll> nums(1e6+1,vll(3,0));
    vll res(1e6+1);
    nums[1]={1,1,1};
    res[1]=3;
    for(int i=2;i<=1e6;i++){
        nums[i][0]=nums[i-1][0]+4*nums[i-1][1]+7*nums[i-1][2];
        nums[i][0]%=MOD;
        nums[i][1]=2*nums[i-1][0]+5*nums[i-1][1]+8*nums[i-1][2];
        nums[i][1]%=MOD;
        nums[i][2]=3*nums[i-1][0]+6*nums[i-1][1]+9*nums[i-1][2];
        nums[i][2]%=MOD;
        res[i]=nums[i][0]+nums[i][1]+nums[i][2];
        res[i]%=MOD;
    }
    scanf("%d",&t);
    while(t--){
        scanf("%d",&a);
        printf("%lld\n",res[a]);
    }
}