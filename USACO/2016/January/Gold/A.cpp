#include <bits/stdc++.h>
using namespace std;
int n,res=2e9;
int main(){
    freopen("angry.in","r",stdin);
    freopen("angry.out","w",stdout);
    cin >> n;
    vector<int> nums(n);
    for(int i=0;i<n;i++){
        cin >> nums[i];
        nums[i]*=2;
    }
    sort(nums.begin(),nums.end());
    vector<int> nue;
    nue.push_back(nums[0]);
    for(int i=1;i<n;i++){
        if(nums[i]!=nums[i-1]){
            nue.push_back(nums[i]);
        }
    }
    nums.clear();
    nums=nue;
    n=nums.size();
    vector<int> psum(n,2e9),ssum(n,2e9);
    psum[0]=-2;
    ssum[n-1]=-2;
    int last=0;
    for(int i=1;i<n;i++){
        while(last+1<i && nums[i]-nums[last+1]>psum[last+1]+2){
            last++;
        }
        psum[i]=min(psum[last+1]+2,nums[i]-nums[last]);
    }
    last=n-1;
    for(int i=n-2;i>=0;i--){
        while(last-1>i && nums[last-1]-nums[i]>ssum[last-1]+2){
            last--;
        }
        ssum[i]=min(ssum[last-1]+2,nums[last]-nums[i]);
    }
    int l=0,r=n-1;
    while(l<r){
        res=min(res,max((nums[r]-nums[l])/2,max(psum[l],ssum[r])+2));
        if(psum[l+1]<ssum[r-1]){
            l++;
        }else{
            r--;
        }
    }
    cout << res/2 << '.';
    if(res%2){
        cout << 5;
    }else{
        cout << 0;
    }
}