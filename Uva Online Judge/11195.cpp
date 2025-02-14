#include <bits/stdc++.h>
using namespace std;
char mat[15][15];
vector<bool> co(15),dia1(30),dia2(30);
int n,con=0,canti=1;
void Queen(int x){
    if(x==n){
        con++;
        return;
    }
    for(int y=0;y<n;y++){
        if(co[y] || dia1[x+y] || dia2[y-x+n-1] || mat[x][y]=='*'){
            continue;
        }
        co[y]=dia1[x+y]=dia2[y-x+n-1]=true;
        Queen(x+1);
        co[y]=dia1[x+y]=dia2[y-x+n-1]=false;
    }
}
int main()
{
    
    //mt19937 rng(chrono::steady_clock().now().time_since_epoch().count());
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);cout.tie(nullptr);
    while(cin >> n && n){
        con=0;
        cout << "Case " << canti << ": ";
        canti++;
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                cin >> mat[i][j];
            }
        }
        Queen(0);
        cout << con << "\n";
    }
}