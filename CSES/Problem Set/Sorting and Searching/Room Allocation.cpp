#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#define ALL(x) x.begin(),x.end()
using namespace __gnu_pbds;
using namespace std;
typedef pair<int,int> pii;
typedef tree<pii,null_type,less<pii>,rb_tree_tag,tree_order_statistics_node_update> indexed_set;
typedef vector<int> vi;
typedef vector<pii> vii;
int n;
int main(){
    scanf("%d",&n);
    vector<vi> nums(n,vi(3));
    for(int i=0;i<n;i++){
        scanf("%d%d",&nums[i][0],&nums[i][1]);
        nums[i][2]=i;
    }
    sort(ALL(nums));
    vi res(n);
    set<pair<int,int>> val;
    int canti=1;
    val.insert({nums[0][1],1});
    res[nums[0][2]]=1;
    for(int i=1;i<n;i++){
        auto p=val.lower_bound({nums[i][0],0});
        if(p==val.begin()){
            canti++;
            res[nums[i][2]]=canti;
        }else{
            p--;
            res[nums[i][2]]=p->second;
            val.erase(p);
        }
        val.insert({nums[i][1],res[nums[i][2]]});
    }
    printf("%d\n",canti);
    for(int i=0;i<n;i++){
        printf("%d ",res[i]);
    }
}