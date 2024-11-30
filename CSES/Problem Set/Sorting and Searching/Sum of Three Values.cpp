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
    for(int i=0;i<n-2&&!xd;i++){
        int target=x-nums[i].first;
        int l=i+1,r=n-1;
        while(l<r){
            if(nums[l].first+nums[r].first==target){
                printf("%d %d %d",nums[i].second,nums[l].second,nums[r].second);
                xd=true;
                break;
            }
            if(nums[l].first+nums[r].first>target){
                r--;
            }else{
                l++;
            }
        }
    }
    if(!xd){
        printf("IMPOSSIBLE");
    }
}