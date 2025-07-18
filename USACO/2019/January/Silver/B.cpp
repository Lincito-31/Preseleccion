#include <bits/stdc++.h>
using namespace std;
int n;
char mat[1002][1002];
bool visited[1002][1002];
pair<int,int> operator +(pair<int,int> x,pair<int,int> y){
    return {x.first+y.first,x.second+y.second};
}
pair<int,int> fill(int x,int y){
    if(visited[x][y] || mat[x][y]=='.'){
        return {0,0};
    }
    visited[x][y]=true;
    pair<int,int> now={1,0};
    if(mat[x-1][y]=='.'){
        now.second++;
    }
    if(mat[x+1][y]=='.'){
        now.second++;
    }
    if(mat[x][y-1]=='.'){
        now.second++;
    }
    if(mat[x][y+1]=='.'){
        now.second++;
    }
    now=now+fill(x-1,y);
    now=now+fill(x+1,y);
    now=now+fill(x,y-1);
    now=now+fill(x,y+1);
    return now;
}
int main(){
    freopen("perimeter.in","r",stdin);
    freopen("perimeter.out","w",stdout);
    cin >> n;
    for(int i=0;i<=n+1;i++){
        mat[0][i]=mat[i][0]=mat[n+1][i]=mat[i][n+1]='.';
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            cin >> mat[i][j];
        }
    }
    pair<int,int> best={0,0};
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            if(!visited[i][j]){
                pair<int,int> now=fill(i,j);
                if(now.first>best.first){
                    best=now;
                }else if(now.first==best.first){
                    best.second=min(best.second,now.second);
                }
            }
        }
    }
    cout << best.first << ' ' << best.second;
}