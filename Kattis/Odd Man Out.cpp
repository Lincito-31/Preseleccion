#include <bits/stdc++.h>
#define ALL(x) x.begin(),x.end()
#define REV(x) x.rbegin(),x.rend()
using namespace std;
typedef long long ll;
typedef long double ld;
int n,g;
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin >> n;
    for(int j=1;j<=n;j++){
        cout << "Case #" << j << ": ";
        cin >> g;
        vector<int> nums(g);
        for(int i=0;i<g;i++){
            cin >> nums[i];
        }
        sort(ALL(nums));
        for(int i=0;i<g;i+=2){
            if(i==g-1){
                cout << nums[i] << '\n';
                break;
            }
            if(nums[i]!=nums[i+1]){
                cout << nums[i] << '\n';
                break;
            }
        }
    }
}