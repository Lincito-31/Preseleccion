#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
using namespace std;
using namespace __gnu_pbds;
typedef long long ll;
typedef tree<pair<int,int>,null_type,less<pair<int,int>>,rb_tree_tag,tree_order_statistics_node_update> indexed_set;
int n,k,a;
int main(){
    indexed_set x;
    scanf("%d%d",&n,&k);
    int nums[n];
    for(int i=0;i<k;i++){
        scanf("%d",&nums[i]);
        x.insert({nums[i],i});
    }
    pair<int,int> mid=(*x.find_by_order((k-1)>>1));
    ll res=0;
    for(int i=0;i<k;i++){
        res+=(ll)abs(mid.first-nums[i]);
    }
    printf("%lld ",res);
    for(int i=k;i<n;i++){
        res-=(ll)abs(mid.first-nums[i-k]);
        x.erase({nums[i-k],i-k});
        pair<int,int> viejo=mid;
        mid=(*x.find_by_order((k-2)>>1));
        if(k%2==0){
            res-=(ll)abs(mid.first-viejo.first);
        }
        scanf("%d",&nums[i]);
        x.insert({nums[i],i});
        viejo=mid;
        mid=(*x.find_by_order((k-1)>>1));
        res+=(ll)(abs(nums[i]-viejo.first));
        if(k%2==1){
            res-=(ll)(abs(mid.first-viejo.first));
        }
        printf("%lld ",res);
    }
}