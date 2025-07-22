#include <bits/stdc++.h>
#define MOD 1000000007
using namespace std;
typedef long long ll;
int n,hel;
set<int> lis;
int main(){
    cin >> n;
    int a[n],pos[n],nums[n];
    for(int i=0;i<n;i++){
        cin >> a[i];
    }
    for(int i=0;i<n;i++){
        cin >> hel;
        pos[--hel]=i;
    }
    for(int i=0;i<n;i++){
        nums[pos[--a[i]]]=i;
    }
    for(int i=0;i<n;i++){
        if(lis.upper_bound(nums[i])!=lis.end()){
            lis.erase(lis.upper_bound(nums[i]));
        }
        lis.insert(nums[i]);
    }
    cout << lis.size();
}