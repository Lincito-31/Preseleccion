#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll res=1;
int n,psum[2501][2501];
bool cmp(pair<int,int> x,pair<int,int> y){
    return x.second<y.second;
}
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie();
    cin >> n;
    pair<int,int> nums[n];
    for(int i=0;i<n;i++){
        cin >> nums[i].first >> nums[i].second;
    }
    sort(nums,nums+n);
    for(int i=0;i<n;i++){
        nums[i].first=i+1;
    }
    sort(nums,nums+n,cmp);
    for(int i=0;i<n;i++){
        nums[i].second=i+1;
    }
    for(int i=0;i<n;i++){
        psum[nums[i].first][nums[i].second]++;
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            psum[i][j]+=psum[i-1][j]+psum[i][j-1]-psum[i-1][j-1];
        }
    }
    for(int i=0;i<n;i++){
        for(int j=i;j<n;j++){
            int t=min(nums[i].first,nums[j].first);
            int b=max(nums[i].first,nums[j].first);
            ll arr=psum[t][nums[j].second]-psum[0][nums[j].second]-psum[t][nums[i].second-1]+psum[0][nums[i].second-1];
            ll ab=psum[n][nums[j].second]-psum[b-1][nums[j].second]-psum[n][nums[i].second-1]+psum[b-1][nums[i].second-1];
            res+=arr*ab;
        }
    }
    cout << res;
}