#include <bits/stdc++.h>
#define ALL(x) x.begin(),x.end()
#define REV(x) x.rbegin(),x.rend()
using namespace std;
typedef long long ll;
int n,m,r,c;
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin >> n >> m >> r >> c;
    char mat[n][m];
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin >> mat[i][j];
        }
    }
    for(int i=0;i<n*r;i++){
        for(int j=0;j<m*c;j++){
            cout << mat[i/r][j/c];
        }
        cout << '\n';
    }
}