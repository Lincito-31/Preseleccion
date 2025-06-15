#include <bits/stdc++.h>
using namespace std;
int n,m,con[5];
char mat[20][20];
void dfs(int i,int j){
    if(i<=0 || i>n || j<0 || j>m){
        return;
    }
    char x=mat[i][j];
    mat[i][j]='.';
    if(mat[i][j-1]==x){
        dfs(i,j-1);
    }
    if(mat[i][j+1]==x){
        dfs(i,j+1);
    }
    if(mat[i-1][j]==x){
        dfs(i-1,j);
    }
    if(mat[i+1][j]==x){
        dfs(i+1,j);
    }
}
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin >> n >> m;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            cin >> mat[i][j];
        }
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            if(mat[i][j]!='.'){
                if(mat[i][j]==mat[i+1][j] && mat[i][j]==mat[i][j+1] && mat[i][j]==mat[i+1][j+1]){
                    con[0]++;
                    mat[i][j]=mat[i+1][j]=mat[i][j+1]=mat[i+1][j+1]='.';
                }else if(mat[i][j]==mat[i][j+1] && mat[i][j]==mat[i][j+2] && mat[i][j]==mat[i][j+3]){
                    mat[i][j]=mat[i][j+1]=mat[i][j+2]=mat[i][j+3]='.';
                    con[1]++;
                }else if(mat[i][j]==mat[i+1][j] && mat[i][j]==mat[i+2][j] && mat[i][j]==mat[i+3][j]){
                    mat[i][j]=mat[i+1][j]=mat[i+2][j]=mat[i+3][j]='.';
                    con[1]++;
                }else if(mat[i][j]==mat[i][j+1] && mat[i][j]==mat[i+1][j+1] && mat[i][j]==mat[i+1][j+2]){
                    mat[i][j]=mat[i][j+1]=mat[i+1][j+1]=mat[i+1][j+2]='.';
                    con[3]++;
                }else if(mat[i][j]==mat[i+1][j] && mat[i][j]==mat[i][j+1] && mat[i][j]==mat[i+1][j-1]){
                    mat[i][j]=mat[i+1][j]=mat[i][j+1]=mat[i+1][j-1]='.';
                    con[2]++;
                }else if(mat[i][j]==mat[i+1][j] && mat[i][j]==mat[i+1][j-1] && mat[i][j]==mat[i+2][j-1]){
                    mat[i][j]=mat[i+1][j]=mat[i+1][j-1]=mat[i+2][j-1]='.';
                    con[3]++;
                }else if(mat[i][j]==mat[i+1][j] && mat[i][j]==mat[i+1][j+1] && mat[i][j]==mat[i+2][j+1]){
                    mat[i][j]=mat[i+1][j]=mat[i+1][j+1]=mat[i+2][j+1]='.';
                    con[2]++;
                }else{
                    con[4]++;
                    dfs(i,j);
                }
            }
        }
    }
    for(int i=0;i<5;i++){
        cout << con[i] << '\n';
    }
}