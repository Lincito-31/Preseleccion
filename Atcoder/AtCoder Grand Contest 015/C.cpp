#include <bits/stdc++.h>
using namespace std;
int N,M,Q,u,d,l,r,con;
int psum[2001][2001],ED[2][2001][2001];
char mat[2001][2001];
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin >> N >> M >> Q;
    for(int i=1;i<=N;i++){
        for(int j=1;j<=M;j++){
            cin >> mat[i][j];
            psum[i][j]=mat[i][j]-48+psum[i][j-1];
            ED[0][i][j]=ED[0][i][j-1];
            ED[1][i][j]=ED[1][i-1][j];
            if(mat[i][j]=='1' && mat[i][j-1]=='1'){
                ED[0][i][j]++;
            }
            if(mat[i][j]=='1' && mat[i-1][j]=='1'){
                ED[1][i][j]++;
            }
        }
    }
    for(int i=1;i<=N;i++){
        for(int j=1;j<=M;j++){
            psum[i][j]+=psum[i-1][j];
            ED[0][i][j]+=ED[0][i-1][j];
            ED[1][i][j]+=ED[1][i][j-1];
        }
    }
    while(Q--){
        cin >> u >> l >> d >> r;
        int v=psum[d][r]+psum[u-1][l-1]-psum[d][l-1]-psum[u-1][r];
        int e1=ED[0][d][r]-ED[0][d][l]-ED[0][u-1][r]+ED[0][u-1][l];
        int e2=ED[1][d][r]-ED[1][u][r]-ED[1][d][l-1]+ED[1][u][l-1];
        cout << v-e1-e2 << '\n';
    }
}