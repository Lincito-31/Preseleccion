#include <bits/stdc++.h>
using namespace std;
int N,a;
set<int> nums;
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin >> N;
    while(N--){
        cin >> a;
        auto p=nums.lower_bound(a);
        if(p==nums.end()){
            nums.insert(a);
        }else{
            nums.erase(p);
            nums.insert(a);
        }
    }
    cout << nums.size();
}