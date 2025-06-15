#include <bits/stdc++.h>
using namespace std;
int n,m,k,tipo;
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin >> n >> m >> tipo;
    int A[n+1][m+1],B[n+1][m+1];
    bool bien[n+1][m+1];
    for(int i=1;i<=n;i++){
        for(int j=1;j=m;j++){
            bien[i][j]=false;
            cin >> A[i][j];
        }
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j=m;j++){
            cin >> B[i][j];
        }
    }
    vector<pair<int,int>> op;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            if(!bien[i][j]){
                if(A[i][j]==B[i][j] && A[n-i+1][j]==B[n-i+1][j] && A[i][m-j+1]==B[i][m-j+1] && A[n-i+1][m-j+1]==B[n-i+1][m-j+1]){
                    bien[i][j]=bien[n-i+1][j]=bien[i][m-j+1]=bien[n-i+1][m-i+1]=true;
                }else if(A[i][j]==B[i][m-j+1] && A[n-i+1][j]==B[n-i+1][m-j+1] && A[i][m-j+1]==B[i][j] && A[n-i+1][m-j+1]==B[n-i+1][j]){
                    bien[i][j]=bien[n-i+1][j]=bien[i][m-j+1]=bien[n-i+1][m-i+1]=true;
                    k++;
                    op.push_back{{1}}
                }else if(A[i][j]==B[n-i+1][j] && A[n-i+1][j]==B[i][j] && A[i][m-j+1]==B[n-i+1][m-j+1] && A[n-i+1][m-j+1]==B[i][m-j+1]){
                    bien[i][j]=bien[n-i+1][j]=bien[i][m-j+1]=bien[n-i+1][m-i+1]=true;
                    k++;
                }else if(A[i][j]==B[n-i+1][m-j+1] && A[n-i+1][j]==B[i][m-j+1] && A[i][m-j+1]==B[n-i+1][j] && A[n-i+1][m-j+1]==B[i][j]){
                    bien[i][j]=bien[n-i+1][j]=bien[i][m-j+1]=bien[n-i+1][m-i+1]=true;
                    k+=2;
                }else{
                    cout << -1;
                    return 0;
                }
            }
        }
    }
}