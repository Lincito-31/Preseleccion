#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    set<pair<int,int>> res;
    vector<int> resp;
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        for(int i=0;i<k;i++){
            res.insert({nums[i],i});
        }
        resp.push_back((--res.end())->first);
        for(int i=k;i<nums.size();i++){
            res.erase({nums[i-k],i-k});
            res.insert({nums[i],i});
            resp.push_back((--res.end())->first);
        }
        return resp;
    }
};