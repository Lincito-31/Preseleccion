#include <bits/stdc++.h>
using namespace std;
int n;
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin >> n;
    int mat[n][n];
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cin >> mat[i][j];
        }
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cout << fixed << setprecision(8) << (double)(mat[i][j]+mat[j][i])/2 << " \n"[j==n-1];
        }
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cout << fixed << setprecision(8) << (double)(mat[i][j]-mat[j][i])/2 << " \n"[j==n-1];
        }
    }
}