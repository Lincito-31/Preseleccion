#include <bits/stdc++.h>
using namespace std;
int n;
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);cout.tie(NULL);
    cin >> n;
    vector<int> nums(n+1);
    nums[0]=0;
    for(int i=1;i<=n;i++){
        cin >> nums[i];
    }
    sort(nums.begin(),nums.end());
    for(int i=1;i<=n;i++){
        nums[i]=min(nums[i],nums[i-1]+1);
    }
    cout << nums.back()+1;
}