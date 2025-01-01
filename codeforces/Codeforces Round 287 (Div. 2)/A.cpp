#include <bits/stdc++.h>
using namespace std;
int n,a,k,sum=0,canti=0;
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);cout.tie(NULL);
    cin >> n >> k;
    vector<pair<int,int>> nums(n);
    for(int i=0;i<n;i++){
        cin >> nums[i].first;
        nums[i].second=i+1;
    }
    sort(nums.begin(),nums.end());
    vector<int> res;
    for(auto u:nums){
        if(sum+u.first>k){
            break;
        }
        sum+=u.first;
        res.push_back(u.second);
    }
    n=res.size();
    cout << n << "\n";
    for(int i=0;i<n;i++){
        cout << res[i] << " ";
    }
}