#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        int n=nums.size();
        vector<vector<int>> res;
        sort(nums.begin(),nums.end());
        if(nums.back()<0){
            return res;
        }
        for(int i=0;i<n-2 && nums[i]<=0;i++){
            if(i>0&& nums[i]==nums[i-1]){
                continue;
            }
            int k=n-1;
            for(int j=i+1;j<k && nums[i]+nums[j]<=0;j++){
                if(j>i+1 && nums[j]==nums[j-1]){
                    continue;
                }
                if(nums[i]+nums[j]+nums[k]==0){
                    res.push_back({nums[i],nums[j],nums[k]});
                }else if(nums[i]+nums[j]+nums[k]>0){
                    j--;
                    k--;
                }
            }
        }
        return res;
    }
};