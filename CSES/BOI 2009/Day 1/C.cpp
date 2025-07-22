#include <bits/stdc++.h>
#define MOD 1000000007
using namespace std;
typedef long long ll;
int n;
set<int> lis;
int main(){
    cin >> n;
    pair<int,int> nums[n];
    for(int i=0;i<n;i++){
        cin >> nums[i].first >> nums[i].second;
    }
    sort(nums,nums+n);
    reverse(nums,nums+n);
    for(int i=0;i<n;i++){
        if(lis.upper_bound(nums[i].second)!=lis.end()){
            lis.erase(lis.upper_bound(nums[i].second));
        }
        lis.insert(nums[i].second);
    }
    cout << lis.size();
}