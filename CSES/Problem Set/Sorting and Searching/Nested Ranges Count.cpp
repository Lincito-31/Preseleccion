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
bool form1(vi a,vi b){
    return a[0]==b[0]?a[1]>b[1]:a[0]<b[0];
}
int main(){
    scanf("%d",&n);
    vector<vi> nums(n,vi(3));
    for(int i=0;i<n;i++){
        scanf("%d%d",&nums[i][0],&nums[i][1]);
        nums[i][2]=i;
    }
    sort(ALL(nums),form1);
    vi res1(n);
    vi res2(n);
    indexed_set se;
    for(int i=0;i<n;i++){
        int x=se.order_of_key({nums[i][1],0});
        res2[nums[i][2]]=i-x;
        se.insert({nums[i][1],nums[i][0]});
        
    }
    se.clear();
    reverse(ALL(nums));
    for(int i=0;i<n;i++){
        int x=se.order_of_key({nums[i][1],1e9});
        res1[nums[i][2]]=x;
        se.insert({nums[i][1],nums[i][0]});
    }
    for(int i=0;i<n;i++){
        printf("%d ",res1[i]);
    }
    printf("\n");
    for(int i=0;i<n;i++){
        printf("%d ",res2[i]);
    }
}