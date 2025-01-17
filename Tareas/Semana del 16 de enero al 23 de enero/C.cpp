#include <bits/stdc++.h>
using namespace std;
int n;
vector<int> nums;
vector<vector<int>> dp;
int main(){
    scanf("%d",&n);
    nums.resize(n);
    dp.assign(n,vector<int>(n,1e9));
    for(int i=0;i<n;i++){
        scanf("%d",&nums[i]);
    }
    solve()
}