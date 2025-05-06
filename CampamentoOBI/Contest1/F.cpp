#include <bits/stdc++.h>
using namespace std;
int n,m,con=0;
int mapa[1000][1000];
void fill(int x,int y){
    if(x<0 || x>=n || y<0 || y>=m){
        return;
    }
    if(mapa[x][y]){
        mapa[x][y]=0;
        fill(x-1,y);
        fill(x,y-1);
        fill(x,y+1);
        fill(x+1,y);
    }
}
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin >> n >> m;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin >> mapa[i][j];
        }
    }
    for(int i=0;i<n;i++){
        fill(i,0);
        fill(i,m-1);
    }
    for(int j=0;j<m;j++){
        fill(0,j);
        fill(n-1,j);
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(mapa[i][j]){
                fill(i,j);
                con++;
            }
        }
    }
    cout << con;
}