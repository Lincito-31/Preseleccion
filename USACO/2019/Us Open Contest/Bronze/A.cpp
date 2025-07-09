#include <bits/stdc++.h>
using namespace std;
char mat[12][12];
int posx,posy,dist[12][12];
int main(){
    ifstream in("buckets.in");
    ofstream out("buckets.out");
    for(int i=0;i<=11;i++){
        for(int j=0;j<=11;j++){
            mat[i][j]='R';
        }
    }
    for(int i=1;i<11;i++){
        for(int j=1;j<11;j++){
            in >> mat[i][j];
            if(mat[i][j]=='B'){
                posx=i;
                posy=j;
            }
        }
    }
    queue<pair<int,int>> bfs;
    bfs.push({posx,posy});
    while(!bfs.empty()){
        pair<int,int> point=bfs.front();
        bfs.pop();
        if(mat[point.first][point.second]=='R'){
            continue;
        }
        if(mat[point.first][point.second]=='L'){
            out << dist[point.first][point.second]-1;
            return 0;
        }
        if(dist[point.first-1][point.second]==0){
            dist[point.first-1][point.second]=dist[point.first][point.second]+1;
            bfs.push({point.first-1,point.second});
        }
        if(dist[point.first+1][point.second]==0){
            dist[point.first+1][point.second]=dist[point.first][point.second]+1;
            bfs.push({point.first+1,point.second});
        }
        if(dist[point.first][point.second-1]==0){
            dist[point.first][point.second-1]=dist[point.first][point.second]+1;
            bfs.push({point.first,point.second-1});
        }
        if(dist[point.first][point.second+1]==0){
            dist[point.first][point.second+1]=dist[point.first][point.second]+1;
            bfs.push({point.first,point.second+1});
        }
    }
}