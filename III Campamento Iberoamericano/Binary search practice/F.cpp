#include <bits/stdc++.h>
using namespace std;
int n,k;
int main(){
    freopen("angry.in","r",stdin);
    freopen("angry.out","w",stdout);
    scanf("%d%d",&n,&k);
    vector<int> nums(n);
    for(int i=0;i<n;i++){
        scanf("%d",&nums[i]);
    }
    sort(nums.begin(),nums.end());
    int l=0,r=1e9;
    while(l<r){
        int mid=(l+r)>>1;
        int now=-1,canti=0;
        auto p=upper_bound(nums.begin(),nums.end(),now);
        while(p!=nums.end()){
            p=upper_bound(nums.begin(),nums.end(),(*p)+(mid<<1));
            canti++;
            if(canti>k){
                break;
            }
        }
        if(canti>k){
            l=mid+1;
        }else{
            r=mid;
        }
    }
    printf("%d",l);
}