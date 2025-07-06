#include <bits/stdc++.h>
#define ALL(x) x.begin(),x.end()
using namespace std;
typedef long long ll;
typedef __int128_t lll;
int n,m,con[4];
double now;
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin >> n >> m;
    char mat[n+2][m+2];
    bool visited[n+2][m+2];
    vector<vector<int>> points;
    for(int i=0;i<=n+1;i++){
        for(int j=0;j<=m+1;j++){
            mat[i][j]='.';
            visited[i][j]=false;
        }
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            cin >> mat[i][j];
        }
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            if(mat[i][j]=='*'){
                con[0]=con[1]=con[2]=con[3]=0;
                while(mat[i-(con[0]+1)][j]=='*'){
                    con[0]++;
                }
                while(mat[i+(con[1]+1)][j]=='*'){
                    con[1]++;
                }
                while(mat[i][j-(con[2]+1)]=='*'){
                    con[2]++;
                }
                while(mat[i][j+(con[3]+1)]=='*'){
                    con[3]++;
                }
                int x=min(min(con[0],con[1]),min(con[2],con[3]));
                if(x>0){
                    points.push_back({i,j,x});
                    for(int k=0;k<=x;k++){
                        visited[i-k][j]=visited[i+k][j]=visited[i][j-k]=visited[i][j+k]=true;
                    }
                }
            }
        }
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            if(!visited[i][j] && mat[i][j]=='*'){
                cout << -1;
                return 0;
            }
        }
    }
    cout << points.size() << '\n';
    for(int i=0;i<points.size();i++){
        for(int j=0;j<3;j++){
            cout << points[i][j] << ' ';
        }
        cout << '\n';
    }
}