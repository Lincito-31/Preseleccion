#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;
using namespace std;
typedef tree<int,null_type,less<int>,rb_tree_tag,tree_order_statistics_node_update> indexed_set;
int n,k;
int main(){
    scanf("%d%d",&n,&k);
    indexed_set nums;
    for(int i=1;i<=n;i++){
        nums.insert(i);
    }
    int now=0;
    while(!nums.empty()){
        now+=k;
        now%=nums.size();
        int x=*nums.find_by_order(now);
        printf("%d ",x);
        nums.erase(x);
    }
}