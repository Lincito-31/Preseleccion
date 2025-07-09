#include <bits/stdc++.h>
#define ALL(x) x.begin(),x.end()
using namespace std;
int n,cow1,cow2,con[8];
bool condi[8][8],al_lado[8][8];
unordered_map<string,int> mapa={{"Beatrice",0},{"Belinda",1},{"Bella",2},{"Bessie",3},{"Betsy",4},{"Blue",5},{"Buttercup",6},{"Sue",7}}; 
string st;
vector<int> orden;
vector<bool> visitado(8);
vector<int> res;
bool terminado=false;
void solve(int x){
    if(terminado){
        return;
    }
    if(orden.size()==8){
        //checkear;
        for(int i=0;i<8;i++){
            for(int j=i+1;j<8;j++){
                if(condi[i][j]){
                    if(!al_lado[i][j]){
                        return;
                    }
                }
            }
        }
        terminado=true;
        res=orden;
        return;
    }
    for(int i=0;i<8;i++){
        if(!visitado[i]){
            visitado[i]=true;
            orden.push_back(i);
            al_lado[x][i]=al_lado[i][x]=true;
            solve(i);
            al_lado[x][i]=al_lado[i][x]=false;
            orden.pop_back();
            visitado[i]=false;
        }
    }
}
int main(){
    ifstream in("lineup.in");
    ofstream out("lineup.out");
    in >> n;
    for(int i=0;i<n;i++){
        in >> st;
        cow1=mapa[st];
        for(int j=0;j<4;j++){
            in >> st;
        }
        in >> st;
        cow2=mapa[st];
        condi[cow1][cow2]=condi[cow2][cow1]=true;
        con[cow1]++;
        con[cow2]++;
    }
    for(int i=0;i<8 && !terminado;i++){
        if(con[i]!=2){
            orden.push_back(i);
            visitado[i]=true;
            solve(i);
            orden.pop_back();
            visitado[i]=false;
        }
    }
    for(int i=0;i<8;i++){
        for(auto u:mapa){
            if(u.second==res[i]){
                out << u.first << '\n';
            }
        }
    }
}