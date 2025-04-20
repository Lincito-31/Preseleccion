#include <bits/stdc++.h>
using namespace std;
int n,m,k;
vector<vector<char>> garden;
vector<vector<char>> res;
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    mt19937 rng(chrono::steady_clock().now().time_since_epoch().count());
    cin >> n >> m >> k;
    garden.assign(n+2,vector<char>(m+2,'#'));
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            cin >> garden[i][j];
            if(garden[i][j]=='.'){
                garden[i][j]='X';
            }
        }
    }
    vector<vector<pair<int,int>>> cantilibre(5);
    vector<vector<vector<bool>>> usado(5,vector<vector<bool>>(n+2,vector<bool>(m+2)));
    vector<vector<int>> cantidad(n+2,vector<int>(m+2));
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            if(garden[i][j]=='#'){
                continue;
            }
            int con=0;
            if(garden[i-1][j]=='X'){
                con++;
            }
            if(garden[i+1][j]=='X'){
                con++;
            }
            if(garden[i][j-1]=='X'){
                con++;
            }
            if(garden[i][j+1]=='X'){
                con++;
            }
            cantidad[i][j]=con;
            usado[con][i][j]=true;
            cantilibre[con].push_back({i,j});
        }
    }
    while(clock()/CLOCKS_PER_SEC<10){
        vector<vector<char>> cop_garden(garden);
        /*vector<vector<int>> cop_cantidad(cantidad);
        vector<vector<vector<bool>>> cop_usado(usado);*/
        vector<vector<pair<int,int>>> pos;
        for(int i=4;i>=0;i--){
            if(cantilibre[i].size()>0){
                int x=uniform_int_distribution<int> (0,cantilibre[i].size()-1)(rng);
                //visitado[cantilibre[i][x].first][cantilibre[i][x].second]=true;
                pos[i].push_back(cantilibre[i][x]);
                //pos.push_back(cantilibre[i][x]);
                break;
            }
        }
        while(!(pos[0].empty()&&pos[1].empty()&&pos[2].empty()&&pos[3].empty()&&pos[4].empty())){
            for(int i=4;i>=0;i--){
                if(pos[i].size()>0){
                    int x=uniform_int_distribution<int> (0,pos[i].size()-1)(rng);
                    if(cop_garden[pos[i][x].first][pos[i][x].second]='X'){
                        pos[i].erase(pos[i].begin()+x);
                        i=5;
                        continue;
                    }
                    cop_garden[pos[i][x].first][pos[i][x].second]='.';
                    int ar=0,ab=0,iz=0,de=0;
                    if(cop_garden[pos[i][x].first-1][pos[i][x].second]=='X'){
                        if(cop_garden[pos[i][x].first-2][pos[i][x].second]=='X'){
                            ar++;
                        }
                        if(cop_garden[pos[i][x].first-1][pos[i][x].second-1]=='X'){
                            ar++;
                        }
                        if(cop_garden[pos[i][x].first-1][pos[i][x].second+1]=='X'){
                            ar++;
                        }
                        pos[ar].push_back(make_pair(pos[i][x].first-1,pos[i][x].second));
                    }
                    if(cop_garden[pos[i][x].first+1][pos[i][x].second]=='X'){
                        if(cop_garden[pos[i][x].first+2][pos[i][x].second]=='X'){
                            ab++;
                        }
                        if(cop_garden[pos[i][x].first+1][pos[i][x].second-1]=='X'){
                            ab++;
                        }
                        if(cop_garden[pos[i][x].first+1][pos[i][x].second+1]=='X'){
                            ab++;
                        }
                        pos[ab].push_back(make_pair(pos[i][x].first+1,pos[i][x].second));
                    }
                    if(cop_garden[pos[i][x].first][pos[i][x].second-1]=='X'){
                        if(cop_garden[pos[i][x].first][pos[i][x].second-2]=='X'){
                            iz++;
                        }
                        if(cop_garden[pos[i][x].first-1][pos[i][x].second-1]=='X'){
                            iz++;
                        }
                        if(cop_garden[pos[i][x].first+1][pos[i][x].second-1]=='X'){
                            iz++;
                        }
                        pos[iz].push_back(make_pair(pos[i][x].first,pos[i][x].second-1));
                    }
                    if(cop_garden[pos[i][x].first][pos[i][x].second+1]=='X'){
                        if(cop_garden[pos[i][x].first][pos[i][x].second+2]=='X'){
                            de++;
                        }
                        if(cop_garden[pos[i][x].first-1][pos[i][x].second+1]=='X'){
                            de++;
                        }
                        if(cop_garden[pos[i][x].first+1][pos[i][x].second+1]=='X'){
                            de++;
                        }
                        pos[de].push_back(make_pair(pos[i][x].first,pos[i][x].second+1));
                    }
                }
            }
        }
        /*while(!pos.empty()){
            int a=pos.front().first,b=pos.front().second;
            pos.pop();
            cop_garden[a][b]='.';
            cop_usado[cop_cantidad[a][b]][a][b]=false;
            if(!visitado[i][j])
            cop_cantidad[a][b]=0;
            cop_usado[cop_cantidad[a-1][b]][a-1][b]=false;
            cop_cantidad[a-1][b]--;
            cop_usado[cop_cantidad[a+1][b]][a+1][b]=false;
            cop_cantidad[a+1][b]--;
            cop_usado[cop_cantidad[a][b-1]][a][b-1]=false;
            cop_cantidad[a][b-1]--;
            cop_usado[cop_cantidad[a][b+1]][a][b+1]=false;
            cop_cantidad[a][b+1]--;
        }*/
    }
}