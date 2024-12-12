#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
using namespace std;
using namespace __gnu_pbds;
typedef tree<pair<int,int>,null_type,less<pair<int,int>>,rb_tree_tag,tree_order_statistics_node_update> indexed_set;
int n,k,a;
int main(){
    indexed_set x;
    scanf("%d%d",&n,&k);
    int nums[n];
    for(int i=0;i<k-1;i++){
        scanf("%d",&nums[i]);
        x.insert({nums[i],i});
    }
    for(int i=k-1;i<n;i++){
        scanf("%d",&nums[i]);
        x.insert({nums[i],i});
        int y=(*x.find_by_order((k-1)>>1)).first;
        printf("%d ",y);
        x.erase({nums[i-k+1],i-k+1});
    }
}