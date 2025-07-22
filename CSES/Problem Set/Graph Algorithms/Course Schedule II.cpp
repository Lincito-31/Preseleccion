#include <bits/stdc++.h>
#define ALL(x) x.begin(),x.end()
#define REV(x) x.rbegin(),x.rend()
using namespace std;
typedef long long ll;
int n,m,a,b,deg[100000],prioridad;
vector<int> graph[100000],ord;
priority_queue<int,vector<int>,greater<int>> now;
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin >> n >> m;
    while(m--){
        cin >> a >> b;
        graph[--a].push_back(--b);
        deg[b]++;
    }
    for(int i=0;i<n;i++){
        if(deg[i]==0){
            now.push(i);
        }
    }
    while(!now.empty()){
        int x=now.top();
        now.pop();
        ord.push_back(x);
        for(auto u:graph[x]){
            deg[u]--;
            if(deg[u]==0){
                now.push(u);
            }
        }
    }
    for(auto u:ord){
        cout << u+1 << ' ';
    }
}