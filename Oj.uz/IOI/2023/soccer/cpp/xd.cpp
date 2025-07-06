#include <bits/stdc++.h>
#define ALL(x) x.begin(),x.end()
using namespace std;
typedef vector<int> vi;
int n,con;
vector<vi> mat,psum;
bool xd=true;
int biggest_stadium(int N,vector<vi> F)
{
    n=N;
    mat.assign(N+2,vi(N+2,1));
    psum.assign(N+2,vi(N+2,0));
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            mat[i][j]=F[i-1][j-1];
        }
    }
    for(int i=1;i<=N;i++){
        int j=1;
        for(;j<=N && mat[i][j]==1;j++);
        for(;j<=N && mat[i][j]==0;j++);
        for(;j<=N && mat[i][j]==1;j++);
        if(j<=N){
            xd=false;
        }
    }
    for(int i=1;i<=N;i++){
        int j=1;
        for(;j<=N && mat[j][i]==1;j++);
        for(;j<=N && mat[j][i]==0;j++);
        for(;j<=N && mat[j][i]==1;j++);
        if(j<=N){
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
            cout << hori[i].first << ' ' << hori[i].second << '\n';
        }
        cout << '\n';
        for(int i=0;i<=n+1;i++){
            int j=0;
            for(;j<=n+1 && mat[j][i]==1;j++);
            vert[i].first=j-1;
            j=n+1;
            for(;j>=0 && mat[j][i]==1;j--);
            vert[i].second=j+1;
            cout << vert[i].first << ' ' << vert[i].second << '\n';
        }
        for(int i=1;i<=n+1;i++){
            for(int j=1;j<=n+1;j++){
                psum[i][j]=psum[i-1][j]+psum[i][j-1]-psum[i-1][j-1]+(mat[i][j]==0?1:0);
                cout << psum[i][j] << ' ';
            }
            cout << '\n';
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

int main()
{
    int N;
    assert(1 == scanf("%d", &N));
    std::vector<std::vector<int>> F(N, std::vector<int>(N));
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            assert(1 == scanf("%d", &F[i][j]));
        }
    }
    fclose(stdin);

    int res = biggest_stadium(N, F);

    printf("%d\n", res);
    fclose(stdout);
    return 0;
}
