#include <bits/stdc++.h>
using namespace std;
int n;
bitset<40000000> visited;
vector<short> dist(40000000,50);
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin >> n;
    queue<int> bfs;
    dist[1]=1;
    dist[0]=0;
    visited[0]=true;
    bfs.push(1);
    visited[1]=true;
    while(!visited[n]){
        int top=bfs.front();bfs.pop();
        if(!visited[top+1]){
            dist[top+1]=dist[top]+1;
            visited[top+1]=true;
            bfs.push(top+1);
        }
        if(!visited[top-1]){
            dist[top-1]=dist[top]+1;
            visited[top-1]=true;
            bfs.push(top-1);
        }
        if(top%2==0 && !visited[top/2]){
            dist[top/2]=dist[top]+1;
            visited[top/2]=true;
            bfs.push(top/2);
        }
        int x=top;
        while(3*x<40000000){
            x*=3;
            if(!visited[x]){
                visited[x]=true;
                bfs.push(x);
                dist[x]=dist[top]+1;
            }
        }
    }
    cout << dist[n];
}