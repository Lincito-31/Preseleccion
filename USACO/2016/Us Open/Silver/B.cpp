#include <bits/stdc++.h>
#define ALL(x) x.begin(),x.end()
using namespace std;
int n,k,l,maxi1,maxi2;
int main(){
    ifstream cin("diamond.in");
    ofstream cout("diamond.out");
    cin >> n >> k;
    int nums[n];
    for(int i=0;i<n;i++){
        cin >> nums[i];
    }
    sort(nums,nums+n);
    int res[n];
    for(int i=0;i<n;i++){
        if(nums[i]-nums[l]<=k){
            res[i]=maxi1=max(maxi1,i-l+1);
            if(l==0){
                maxi2=max(maxi2,i-l+1);
            }else{
                maxi2=max(maxi2,i-l+1+res[l-1]);
            }
        }else{
            l++;
            i--;
        }
    }
    cout << maxi2;
}