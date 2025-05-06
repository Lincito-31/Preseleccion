#include <bits/stdc++.h>
using namespace std;
int n,a;
int fila=1,col=1;
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    while(cin >> n){
        fila=1;col=1;
        vector<vector<int>> mat(n+1,vector<int>(n+1)),psum=mat;
        while(cin>>mat[fila][col++]){
            if(col>n){
                col=1;
                fila++;
            }
            if(fila>n){
                break;
            }
        }
        for(int i=1;i<=n;i++){
            for(int j=1;j<=n;j++){
                psum[i][j]=psum[i][j-1]+mat[i][j];
            }
        }
        for(int i=1;i<=n;i++){
            for(int j=1;j<=n;j++){
                psum[i][j]+=psum[i-1][j];
            }
        }
        int maxi=-1e9;
        for(int i=1;i<=n;i++){
            for(int j=1;j<=n;j++){
                for(int k=i;k<=n;k++){
                    for(int l=j;l<=n;l++){
                        maxi=max(maxi,psum[k][l]+psum[i-1][j-1]-psum[k][j-1]-psum[i-1][l]);
                    }
                }
            }
        }
        cout << maxi << "\n";
    }
}