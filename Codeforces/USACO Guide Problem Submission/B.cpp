#include <bits/stdc++.h>
#define ALL(x) x.begin(),x.end()
using namespace std;
int n,k,sum;
int main(){
    cin >> n >> k;
    int nums[n+1];
    for(int i=0;i<n;i++){
        cin >> nums[i];
    }
    nums[n]=1e9;
    sort(nums,nums+n);
    for(int i=0;i<=n;i++){
        if(sum+nums[i]<=k){
            sum+=nums[i];
        }else{
            cout << i;
            break;
        }
    }
}