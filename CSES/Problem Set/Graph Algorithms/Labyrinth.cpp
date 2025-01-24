#include <bits/stdc++.h>
using namespace std;
int Ax,Ay,By,Bx,n,m;
char mat[1000][1000];
bool visited[1000][1000];
pair<int,int> pad[1000][1000];
int main(){
    scanf("%d%d",&n,&m);
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            scanf(" %c",&mat[i][j]);
            if(mat[i][j]=='A'){
                Ax=i;
                Ay=j;
            }
            if(mat[i][j]=='B'){
                Bx=i;
                By=j;
            }
            visited[i][j]=false;
            pad[i][j]={-1,-1};
        }
    }
    queue<pair<int,int>> cola;
    cola.push({Ax,Ay});
    visited[Ax][Ay]=true;
    while(!cola.empty()){
        pair<int,int> top=cola.front();
        cola.pop();
        if(top.first>0){
            if(!(visited[top.first-1][top.second]||(mat[top.first-1][top.second]=='#'))){
                visited[top.first-1][top.second]=true;
                pad[top.first-1][top.second]=top;
                cola.push({top.first-1,top.second});
                if(mat[top.first-1][top.second]=='B'){
                    break;
                }
            }
        }
        if(top.second<m-1){
            if(!(visited[top.first][top.second+1]||(mat[top.first][top.second+1]=='#'))){
                visited[top.first][top.second+1]=true;
                pad[top.first][top.second+1]=top;
                cola.push({top.first,top.second+1});
                if(mat[top.first][top.second+1]=='B'){
                    break;
                }
            }
        }
        if(top.second>0){
            if(!(visited[top.first][top.second-1]||(mat[top.first][top.second-1]=='#'))){
                visited[top.first][top.second-1]=true;
                pad[top.first][top.second-1]=top;
                cola.push({top.first,top.second-1});
                if(mat[top.first][top.second-1]=='B'){
                    break;
                }
            }
        }
        if(top.first<n-1){
            if(!(visited[top.first+1][top.second]||(mat[top.first+1][top.second]=='#'))){
                visited[top.first+1][top.second]=true;
                pad[top.first+1][top.second]=top;
                cola.push({top.first+1,top.second});
                if(mat[top.first+1][top.second]=='B'){
                    break;
                }
            }
        }
    }
    if(visited[Bx][By]){
        printf("YES\n");
        vector<char> res;
        while(!(By==Ay&&Bx==Ax)){
            if(pad[Bx][By].first>Bx){
                res.push_back('U');
            }else if(pad[Bx][By].first<Bx){
                res.push_back('D');
            }else if(pad[Bx][By].second<By){
                res.push_back('R');
            }else{
                res.push_back('L');
            }
            int tempx=pad[Bx][By].first;
            int tempy=pad[Bx][By].second;
            Bx=tempx;
            By=tempy;
        }
        printf("%d\n",res.size());
        for(int i=res.size()-1;i>=0;i--){
            printf("%c",res[i]);
        }
    }else{
        printf("NO\n");
    }
}