#include <bits/stdc++.h>
#define ALL(x) x.begin(),x.end()
#define REV(x) x.rbegin(),x.rend()
using namespace std;
typedef long long ll;
ll sum,n;
int main(){
    cin >> n;
    vector<ll> nums(n),b(n);
    for(int i=0;i<n;i++){
        cin >> nums[i];
        nums[i]*=(i+1)*(n-i);
    }
    sort(ALL(nums));
    for(int i=0;i<n;i++){
        cin >> b[i];
    }
    sort(REV(b));
    for(int i=0;i<n;i++){
        sum+=b[i]*nums[i];
    }
    cout << sum << '\n';
}