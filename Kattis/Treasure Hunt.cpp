#include <bits/stdc++.h>
#define ALL(x) x.begin(),x.end()
using namespace std;
typedef long long ll;
int r,c;
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin >> r >> c;
    char mat[r][c];
    for(int i=0;i<r;i++){
        for(int j=0;j<c;j++){
            cin >> mat[i][j];
        }
    }
    int x=0,y=0,canti=0;
    while(mat[x][y]!='T'){
        if(mat[x][y]=='.'){
            cout << "Lost";
            return 0;
        }else if(mat[x][y]=='S'){
            mat[x][y]='.';
            x++;
        }else if(mat[x][y]=='E'){
            mat[x][y]='.';
            y++;
        }else if(mat[x][y]=='W'){
            mat[x][y]='.';
            y--;
        }else{
            mat[x][y]='.';
            x--;
        }
        if(x<0 || y<0 || x>=r || y>=c){
            cout << "Out";
            return 0;
        }
        canti++;
    }
    cout << canti;
}