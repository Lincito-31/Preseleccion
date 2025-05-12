/*
ID: simplem2
TASK: skidesign
LANG: C++
*/
#include <bits/stdc++.h>
#define ALL(x) x.begin(),x.end()
using namespace std;
typedef long long ll;
int n,mini=1e9,sum,minii=1e9,maxii;
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    freopen("skidesign.in","r",stdin);
    freopen("skidesign.out","w",stdout);
    cin >> n;
    int nums[n];
    for(int i=0;i<n;i++){
        cin >> nums[i];
        maxii=max(nums[i],maxii);
        minii=min(minii,nums[i]);
    }
    for(int i=0;i<=83;i++){
        sum=0;
        for(int j=0;j<n;j++){
            if(nums[j]<i){
                sum+=(nums[j]-i)*(nums[j]-i);
            }else if(i+17<nums[j]){
                sum+=(nums[j]-(i+17))*(nums[j]-(i+17));
            }
        }
        mini=min(mini,sum);
    }
    cout << mini << '\n';
}