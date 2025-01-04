#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;
using namespace std;
typedef tree<pair<int,int>,null_type,less<pair<int,int>>,rb_tree_tag,tree_order_statistics_node_update> indexed_set;
int n;
int main(){
    while(scanf("%d",&n),n!=-1){
        vector<pair<int,int>> nums(n);
        for(int i=0;i<n;i++){
            scanf("%d%d",&nums[i].first,&nums[i].second);
        }
        sort(nums.begin(),nums.end());
        vector<int> dp(n);
        dp[0]=1;
        indexed_set conjunt;
        conjunt.insert({nums[0].second,0});
        for(int i=1;i<n;i++){
            dp[i]=dp[i-1]+conjunt.order_of_key({nums[i].first,1e9})+1;
            conjunt.insert({nums[i].second,i});
        }
        printf("%d\n",dp[n-1]);
    }
}