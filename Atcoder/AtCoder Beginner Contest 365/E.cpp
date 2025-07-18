#include <bits/stdc++.h>
#define ALL(x) x.begin(),x.end()
using namespace std;
typedef long long ll;
int n;
ll res;
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin >> n;
    int nums[n];
    for(int i=0;i<n;i++){
        cin >> nums[i];
    }
    for(int j=0;j<32;j++){
        ll psum[n],suma=0;
        if(nums[0]&(1<<j)){
            psum[0]=1;
        }else{
            psum[0]=0;
        }
        for(int i=1;i<n;i++){
            if(nums[i]&(1<<j)){
                psum[i]=1+i-psum[i-1];
            }else{
                psum[i]=psum[i-1];
            }
            suma+=psum[i];
            if(nums[i]&(1<<j)){
                suma--;
            }
        }
        res+=suma<<j;
    }
    cout << res;
}