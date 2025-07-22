#include <bits/stdc++.h>
#define ALL(x) x.begin(),x.end()
#define REV(x) x.rbegin(),x.rend()
using namespace std;
typedef long long ll;
int n,m,a,b,target=-1;
vector<int> graph[100000];
bool visited[100000],on_stack[100000],xd;
vector<int> state,res;
void dfs(int x){
    on_stack[x]=true;
    state.push_back(x);
    for(auto u:graph[x]){
        if(on_stack[u]){
            int target=u;
            res.push_back(u);
            while(state.back()!=target){
                res.push_back(state.back());
                state.pop_back();
            }
            res.push_back(u);
            xd=true;
            return;;
        }
        if(visited[u]){
            continue;
        }
        visited[u]=true;
        dfs(u);
        if(xd){
            return;
        }
    }
    on_stack[x]=false;
    state.pop_back();
}
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin >> n >> m;
    while(m--){
        cin >> a >> b;
        graph[--a].push_back(--b);
    }
    for(int i=0;i<n;i++){
        if(!visited[i]){
            visited[i]=true;
            dfs(i);
            if(xd){
                cout << res.size() << '\n';
                reverse(res.begin(),res.end());
                for(auto u:res){
                    cout << u+1 << ' ';
                }
                return 0;
            }
        }
    }
    cout << "IMPOSSIBLE";
}