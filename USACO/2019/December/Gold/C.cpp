#include <bits/stdc++.h>
using namespace std;
int n,m,k,x;
char st[100001];
vector<pair<int,int>> graph[26];
int dist[26][26];
vector<bool> visited;
int psum[26][1000001];
int dp[100001];
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    ifstream in("cowmbat.in");
    ofstream out("cowmbat.out");
    in >> n >> m >> k;
    for(int i=1;i<=n;i++){
        in >> st[i];
        for(int j=0;j<26;j++){
            psum[j][i]+=psum[j][i-1];
        }
        psum[st[i]-'a'][i]++;
    }
    for(int i=0;i<m;i++){
        for(int j=0;j<m;j++){
            in >> x;
            if(i==j){
                continue;
            }
            graph[i].push_back({j,x});
        }
    }
    for(int i=0;i<26;i++){
        for(int j=0;j<26;j++){
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
    for(int i=0;i<=n;i++){
        dp[i]=1e9;
    }
    dp[0]=0;
    for(int i=k;i<=n;i++){
        // del dp[i-2*k] al dp[i][k];
        for(int j=k;j<2*k;j++){
            //rango desde i-j+1 al i;
            if(i-j<0){
                break;
            }
            vector<int> cant(26);
            for(int l=0;l<26;l++){
                cant[l]=psum[l][i]-psum[l][i-j];
            }
            int mini=1e9,val;
            for(int l=0;l<m;l++){
                val=0;
                for(int h=0;h<m;h++){
                    val+=dist[h][l]*cant[h];
                }
                mini=min(mini,val);
            }
            dp[i]=min(dp[i],dp[i-j]+mini);
        }
    }
    out << dp[n];
}