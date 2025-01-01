#include <bits/stdc++.h>
using namespace std;
int n,g,s,b;
string st;
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);cout.tie(NULL);
    cin >> n;
    vector<pair<vector<int>,string>> nums(n);
    while(n--){
        cin >> g >> s >> b;
        getline(cin,st);
        nums[n]={{g,s,b},st};
    }
    sort(nums.rbegin(),nums.rend());
    cout << nums[0].second;
}