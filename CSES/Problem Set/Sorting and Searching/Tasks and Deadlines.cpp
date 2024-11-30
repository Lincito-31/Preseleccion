#include <bits/stdc++.h>
using namespace std;
int n,a,b;
bool cmp(pair<int,int> x,pair<int,int> y){
    if(x.first==y.first){
        return x.second>y.second;
    }
    return x.first<y.first;
}
int main(){
    scanf("%d",&n);
    vector<pair<int,int>> nums(n);
    for(int i=0;i<n;i++){
        scanf("%d%d",&nums[i].first,&nums[i].second);
    }
    sort(nums.begin(),nums.end(),cmp);
    long long res=0;
    long long now=0;
    for(int i=0;i<n;i++){
        now+=nums[i].first;
        res+=nums[i].second-now;
    }
    printf("%lld",res);
}