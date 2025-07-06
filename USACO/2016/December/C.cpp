#include <bits/stdc++.h>
using namespace std;
int n,m,c;
int main(){
    ifstream in("cowsignal.in");
    ofstream out("cowsignal.out");
    in >> n >> m >> c;
    char mat[n][m];
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            in >> mat[i][j];
        }
    }
    for(int i=0;i<n*c;i++){
        for(int j=0;j<m*c;j++){
            out << mat[i/c][j/c];
        }
        out << '\n';
    }
}