#include <bits/stdc++.h>
#define MOD 1000000007
using namespace std;
int n;
int main(){
    scanf("%d",&n);
    int nums[n];
    vector<int> dp;
    for(int i=0;i<n;i++){
        scanf("%d",&nums[i]);
        auto it=lower_bound(dp.begin(),dp.end(),nums[i]);
        if(it==dp.end()){
            dp.push_back(nums[i]);
        }else{
            *it=nums[i];
        }
    }
    printf("%d",dp.size());
}