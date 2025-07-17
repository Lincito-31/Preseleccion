#include <bits/stdc++.h>
using namespace std;
int n,m,k,x,psum[1000001][26],dp[100001][26],dist[26][26],mini[100001];
char st[100001];
vector<pair<int,int>> graph[26];
vector<bool> visited;
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    ifstream fin("cowmbat.in");
    ofstream fout("cowmbat.out");
    fin >> n >> m >> k;
    for(int i=1;i<=n;i++){
        fin >> st[i];
    }
    for(int i=0;i<m;i++){
        for(int j=0;j<m;j++){
            fin >> x;
            if(i==j){
                continue;
            }
            graph[i].push_back({j,x});
        }
    }
    for(int i=0;i<m;i++){
        for(int j=0;j<m;j++){
            if(i==j){
                dist[i][j]=0;
                continue;
            }
            dist[i][j]=1e9;
        }
    }
    for(int i=0;i<m;i++){
        visited.clear();
        visited.resize(26);
        priority_queue<pair<int,int>> dijs;
        dijs.push({0,i});
        while(!dijs.empty()){
            x=dijs.top().second;
            dijs.pop();
            if(visited[x]){
                continue;
            }
            visited[x]=true;
            for(auto u:graph[x]){
                if(u.second+dist[i][x]<dist[i][u.first]){
                    dist[i][u.first]=u.second+dist[i][x];
                    dijs.push({-dist[i][u.first],u.first});
                }
            }
        }
    }
    for(int i=1;i<=n;i++){
        for(int j=0;j<m;j++){
            psum[i][j]=psum[i-1][j]+dist[st[i]-'a'][j];
        }
    }
    for(int i=0;i<=n;i++){
        for(int j=0;j<26;j++){
            dp[i][j]=1e9;
        }
        mini[i]=1e9;
    }
    mini[0]=0;
    for(int i=1;i<=n;i++){
        for(int j=0;j<m;j++){
            dp[i][j]=min(dp[i][j],dp[i-1][j]+dist[st[i]-'a'][j]);
            if(i>=k){
                dp[i][j]=min(dp[i][j],mini[i-k]+psum[i][j]-psum[i-k][j]);
            }
            mini[i]=min(mini[i],dp[i][j]);
        }
    }
    fout << mini[n];
}