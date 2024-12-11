#include <bits/stdc++.h>
using namespace std;
int n,a;
int main(){
    cin>>n;
    stack<pair<int,int>> p;
    p.push({-1,0});
    for(int i=0;i<n;i++){
        cin>>a;
        while(a<=p.top().first)p.pop();
        cout<<p.top().second<<" ";
        p.push({a,i+1});
    }
}