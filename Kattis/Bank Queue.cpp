#include <bits/stdc++.h>
using namespace std;
int n,t,a,b;
priority_queue<int,vector<int>,greater<int>> pq;
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin >> n >> t;
    vector<int> nums[t];
    while(n--){
        cin >> a >> b;
        nums[b].push_back(a);
    }
    for(int i=b=0;i<t;i++){
        pq.push(0);
        for(int j:nums[i]){
            a=pq.top();
            if(a<j){
                b+=-a+j;
                pq.pop();
                pq.push(j);
            }
        }
    }
    cout << b;
}