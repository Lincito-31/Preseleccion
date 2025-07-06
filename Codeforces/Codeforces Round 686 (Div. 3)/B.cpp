#include <bits/stdc++.h>
#define ALL(x) x.begin(),x.end()
using namespace std;
typedef vector<int> vi;
typedef pair<int,int> pii;
int t,n,a;
int main(){
    scanf("%d",&t);
    while(t--){
        int res=-1;
        scanf("%d",&n);
        vector<pii> nums(n);
        for(int i=0;i<n;i++){
            scanf("%d",&nums[i].first);
            nums[i].second=i+1;
        }
        if(n==1){
            printf("1\n");
            continue;
        }
        sort(ALL(nums));
        if(nums[0].first==nums[1].first){
            for(int i=1;i<n-1;i++){
                if(nums[i].first!=nums[i-1].first && nums[i].first!=nums[i+1].first){
                    res=nums[i].second;
                    break;
                }
            }
            if(res==-1 && nums[n-2].first!=nums[n-1].first){
                res=nums[n-1].second;
            }
        }else{
            res=nums[0].second;
        }
        printf("%d\n",res);
    }
}