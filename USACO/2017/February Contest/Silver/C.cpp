#include <bits/stdc++.h>
#define ALL(x) x.begin(),x.end()
using namespace std;
int n,k,r,a,b,c,d,mat[102][102],color,resp;
vector<vector<int>> road;
void fill(int x,int y){
    if(x==0 || y==0 || x==n+1 || y==n+1){
        return;
    }
    if(mat[x][y]!=0){
        return;
    }
    mat[x][y]=color;
    vector<int> bus={x-1,y,x,y};
    if(!binary_search(ALL(road),bus)){
        fill(x-1,y);
    }
    bus={x,y,x+1,y};
    if(!binary_search(ALL(road),bus)){
        fill(x+1,y);
    }
    bus={x,y-1,x,y};
    if(!binary_search(ALL(road),bus)){
        fill(x,y-1);
    }
    bus={x,y,x,y+1};
    if(!binary_search(ALL(road),bus)){
        fill(x,y+1);
    }
    return;
}
int main(){
    freopen("countcross.in","r",stdin);
    freopen("countcross.out","w",stdout);
    cin >> n >> k >> r;
    road.resize(r);
    for(int i=0;i<r;i++){
        cin >> a >> b >> c >> d;
        if(a<c){
            road[i]={a,b,c,d};
        }else if(c<a){
            road[i]={c,d,a,b};
        }else{
            road[i]={a,min(b,d),c,max(b,d)};
        }
    }
    sort(ALL(road));
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            if(mat[i][j]==0){
                color++;
                fill(i,j);
            }
            //cout << mat[i][j];
        }
        //cout << endl;
    }
    vector<int> conjunto(color+1);
    for(int i=0;i<k;i++){
        cin >> a >> b;
        conjunto[mat[a][b]]++;
    }
    for(int i=0;i<=color;i++){
        for(int j=i+1;j<=color;j++){
            resp+=conjunto[i]*conjunto[j];
        }
    }
    cout << resp;
}