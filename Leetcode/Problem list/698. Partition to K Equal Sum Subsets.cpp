#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int N,K,sum=0,prom;
    vector<int> NUMS;
    vector<bool> usado;
    bool xd=false;
    bool calc(int sumanow,int canti,int position){
        if(sumanow==prom){
            return true;
        }
        for(int i=0;i<N;i++){
            if(usado[i]){
                continue;
            }
        }
    }
    bool canPartitionKSubsets(vector<int>& nums, int k){
        N=nums.size();
        K=k;
        NUMS=nums;
        usado.assign(N+1,false);
        for(int i=0;i<N;i++){
            sum+=nums[i];
        }
        prom=sum/k;
        if(prom*k!=sum){
            return false;
        }
        calc(0,0,0);
        return xd;
    }
};