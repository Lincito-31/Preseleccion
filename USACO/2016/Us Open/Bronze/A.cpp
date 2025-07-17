#include <bits/stdc++.h>
#define ALL(x) x.begin(),x.end()
using namespace std;
int n,k,l,maxi;
int main(){
    ifstream in("diamond.in");
    ofstream out("diamond.out");
    in >> n >> k;
    int nums[n];
    for(int i=0;i<n;i++){
        in >> nums[i];
    }
    sort(nums,nums+n);
    for(int i=0;i<n;i++){
        if(nums[i]-nums[l]<=k){
            maxi=max(i-l+1,maxi);
        }else{
            l++;
            i--;
        }
    }
    out << maxi;
}