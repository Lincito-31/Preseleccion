#include <bits/stdc++.h>
using namespace std;
int state[301][301][301];
/*bool solve(int x,int y,int z){
    if(state[x][y][z]==1){
        return true;
    }
    if(state[x][y][z]==2){
        return false;
    }

}*/
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    for(int i=0;i<=300;i++){
        for(int j=0;j<=300;j++){
            for(int k=0;k<=300;k++){
                state[i][j][k]=0;
                //solve(min({i,j,k}),i+j+k-min({i,j,k})-max({i,j,k}),max({i,j,k}));
            }
        }
    }
    for(int i=0;i<=300;i++){
        for(int j=0;j<=300;j++){
            for(int k=0;k<=300;k++){
                if(state[i][j][k]==1){
                    continue;
                }
                if(i<=j && j<=k){
                    cout << i << " " << j << " " << k << "\n";
                }
                for(int aux=1;aux<=300;aux++){
                    if(aux+i<=300){
                        state[aux+i][j][k]=1;
                    }
                    if(aux+j<=300){
                        state[i][aux+j][k]=1;
                    }
                    if(aux+k<=300){
                        state[i][j][aux+k]=1;
                    }
                }
            }
        }
    }
}