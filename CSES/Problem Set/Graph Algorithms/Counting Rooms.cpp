#include <bits/stdc++.h>
using namespace std;
int n,m;
int main(){
    scanf("%d%d",&n,&m);
    char mat[n][m];
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            scanf(" %c",&mat[i][j]);
        }
    }
    int con=0;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(mat[i][j]=='.'){
                con++;
                queue<pair<int,int>> cola;
                cola.push({i,j});
                while(!cola.empty()){
                    pair<int,int> a=cola.front();cola.pop();
                    int x=a.first,y=a.second;
                    if(x>=n || x<0 || y>=m || y<0){
                        continue;
                    }
                    if(mat[x][y]=='#'){
                        continue;
                    }
                    mat[x][y]='#';
                    cola.push({x+1,y});
                    cola.push({x-1,y});
                    cola.push({x,y+1});
                    cola.push({x,y-1});
                }
            }
        }
    }
    printf("%d",con);
}