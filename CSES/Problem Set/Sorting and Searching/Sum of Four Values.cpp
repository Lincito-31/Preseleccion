#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int n,x;
int main(){
    scanf("%d%d",&n,&x);
    vector<pair<int,int>> nums(n);
    for(int i=0;i<n;i++){
        scanf("%d",&nums[i].first);
        nums[i].second=i+1;
    }
    sort(nums.begin(),nums.end());
    bool xd=false;
    for(int i=0;i<n-3&&!xd;i++){
        int target1=x-nums[i].first;
        if(target1<3*nums[i].first){
            break;
        }
        for(int j=i+1;j<n-2&&!xd;j++){
            int target2=target1-nums[j].first;
            if(target2<2*nums[j].first){
                break;
            }
            int l=i+1,r=n-1;
            while(l<r){
                if(nums[l].first+nums[r].first==target2){
                    printf("%d %d %d",nums[i].second,nums[l].second,nums[r].second);
                    xd=true;
                    break;
                }
                if(nums[l].first+nums[r].first>target2){
                    r--;
                }else{
                    l++;
                }
            }
        }
    }
    if(!xd){
        printf("IMPOSSIBLE");
    }
}