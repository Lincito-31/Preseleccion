#include <bits/stdc++.h>
#define ALL(x) x.begin(),x.end()
#define REV(x) x.rbegin(),x.rend()
using namespace std;
typedef long long ll;
int sum,n,mini=1e9;
int main(){
    cin >> n;
    vector<int> nums(n*=2);
    for(int i=0;i<n;i++){
        cin >> nums[i];
    }
    sort(ALL(nums));
    for(int i=0;i<n;i++){
        for(int j=i+1;j<n;j++){
            int last=-1;
            int maxi=0;
            for(int k=0;k<n;k++){
                if(k==i || k==j){
                    continue;
                }
                if(last==-1){
                    last=nums[k];
                }else{
                    maxi+=nums[k]-last;
                    last=-1;
                }
            }
            mini=min(mini,maxi);
        }
    }
    cout << mini;
}