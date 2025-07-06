#include "soccer.h"
#include <bits/stdc++.h>
#define ALL(x) x.begin(),x.end()
using namespace std;
typedef vector<int> vi;
int n,maxi=1;
vector<vi> mat;
vector<pair<int,int>> trees;
void solve(int x,int y){
    if(y>n){
        solve(x+1,1);
        return;
    }
    if(x>n){
        bool xd=true;
        int con=0;
        vector<vi> psum(n+2,vi(n+2,0));
        for(int i=1;i<=n;i++){
            int j=1;
            for(;j<=n && mat[i][j]==1;j++);
            for(;j<=n && mat[i][j]==0;j++);
            for(;j<=n && mat[i][j]==1;j++);
            if(j<=n){
                xd=false;
            }
        }
        for(int i=1;i<=n;i++){
            int j=1;
            for(;j<=n && mat[j][i]==1;j++);
            for(;j<=n && mat[j][i]==0;j++);
            for(;j<=n && mat[j][i]==1;j++);
            if(j<=n){
                xd=false;
            }
        }
        vector<pair<int,int>> hori(n+2),vert(n+2);
        if(xd){
            for(int i=0;i<=n+1;i++){
                int j=0;
                for(;j<=n+1 && mat[i][j]==1;j++);
                hori[i].first=j-1;
                j=n+1;
                for(;j>=0 && mat[i][j]==1;j--);
                hori[i].second=j+1;
            }
            for(int i=0;i<=n+1;i++){
                int j=0;
                for(;j<=n+1 && mat[j][i]==1;j++);
                vert[i].first=j-1;
                j=n+1;
                for(;j>=0 && mat[j][i]==1;j--);
                vert[i].second=j+1;
            }
            for(int i=1;i<=n+1;i++){
                for(int j=1;j<=n+1;j++){
                    psum[i][j]=psum[i-1][j]+psum[i][j-1]-psum[i-1][j-1]+(mat[i][j]==0?1:0);
                }
            }
            for(int i=1;i<=n;i++){
                for(int j=1;j<=n;j++){
                    if(mat[i][j]==0){
                        con++;
                        //izquierda arriba;
                        //hori[i].first vert[i].first;
                        if(psum[vert[j].first][hori[i].first]>0){
                            xd=false;
                        }
                        //izquierda abajo;
                        if(psum[n][hori[i].first]-psum[vert[j].second-1][hori[i].first]-psum[n][0]+psum[vert[j].second-1][0]>0){
                            xd=false;
                        }
                    }
                }
            }
            if(xd){
                maxi=max(maxi,con);
            }
        }
        return;
    }
    solve(x,y+1);
    if(mat[x][y]==0){
        mat[x][y]=1;
        solve(x,y+1);
        mat[x][y]=0;
    }
    return;
}
int biggest_stadium(int N,vector<vi> F)
{
    n=N;
    mat.assign(n+2,vi(n+2,1));
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            mat[i][j]=F[i-1][j-1];
            if(mat[i][j]){
                trees.push_back({i,j});   
            }
        }
    }
    if(trees.size()==0){
        return n*n;
    }else if(trees.size()==1){
        int x=max(trees[0].first-1,n-trees[0].first);
        int y=max(trees[0].second-1,n-trees[0].second);
        return (x+y)*n-x*y;
    }else if(n<=3){
        solve(1,1);
        return maxi;
    }else{
        bool xd=true;
        int con=0;
        vector<vi> psum;
        psum.assign(n+2,vi(n+2,0));
        for(int i=1;i<=n;i++){
            int j=1;
            for(;j<=n && mat[i][j]==1;j++);
            for(;j<=n && mat[i][j]==0;j++);
            for(;j<=n && mat[i][j]==1;j++);
            if(j<=n){
                xd=false;
            }
        }
        for(int i=1;i<=n;i++){
            int j=1;
            for(;j<=n && mat[j][i]==1;j++);
            for(;j<=n && mat[j][i]==0;j++);
            for(;j<=n && mat[j][i]==1;j++);
            if(j<=n){
                xd=false;
            }
        }
        vector<pair<int,int>> hori(n+2),vert(n+2);
        if(xd){
            for(int i=0;i<=n+1;i++){
                int j=0;
                for(;j<=n+1 && mat[i][j]==1;j++);
                hori[i].first=j-1;
                j=n+1;
                for(;j>=0 && mat[i][j]==1;j--);
                hori[i].second=j+1;
            }
            for(int i=0;i<=n+1;i++){
                int j=0;
                for(;j<=n+1 && mat[j][i]==1;j++);
                vert[i].first=j-1;
                j=n+1;
                for(;j>=0 && mat[j][i]==1;j--);
                vert[i].second=j+1;
            }
            for(int i=1;i<=n+1;i++){
                for(int j=1;j<=n+1;j++){
                    psum[i][j]=psum[i-1][j]+psum[i][j-1]-psum[i-1][j-1]+(mat[i][j]==0?1:0);
                }
            }
            for(int i=1;i<=n;i++){
                for(int j=1;j<=n;j++){
                    if(mat[i][j]==0){
                        con++;
                        //izquierda arriba;
                        //hori[i].first vert[i].first;
                        if(psum[vert[j].first][hori[i].first]>0){
                            xd=false;
                        }
                        //izquierda abajo;
                        if(psum[n][hori[i].first]-psum[vert[j].second-1][hori[i].first]-psum[n][0]+psum[vert[j].second-1][0]>0){
                            xd=false;
                        }
                    }
                }
            }
            if(xd){
                return con;
            }else{
                return 1;
            }
        }else{
            return 1;
        }
    }
}