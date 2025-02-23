#include <bits/stdc++.h>
using namespace std;
int n,m,a,b;
char c;
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin >> n >> m;
    vector<vector<bool>> mat(n,vector<bool>(n,false));
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cin >> c;
            if(c=='#'){
                mat[i][j]=true;
            }
        }
    }
    vector<vector<int>> sum(n,vector<int>(n,0));
    int canti=0;
    for(int i=0;i<n/2;i++){
        for(int j=0;j<n/2;j++){
            int aste=0;
            aste+=((mat[i][j])?1:0);
            aste+=((mat[n-i-1][j])?1:0);
            aste+=((mat[n-i-1][n-j-1])?1:0);
            aste+=((mat[i][n-j-1])?1:0);
            canti+=min(aste,4-aste);
            sum[i][j]=min(aste,4-aste);
        }
    }
    cout << canti << "\n";
    while(m--){
        cin >> a >> b;
        a--;b--;
        mat[a][b]=!mat[a][b];
        if(a>=n/2){
            a=n-a-1;
        }
        if(b>=n/2){
            b=n-b-1;
        }
        canti-=sum[a][b];
        int aste=0;
        aste+=((mat[a][b])?1:0);
        aste+=((mat[n-a-1][b])?1:0);
        aste+=((mat[n-a-1][n-b-1])?1:0);
        aste+=((mat[a][n-b-1])?1:0);
        canti+=min(aste,4-aste);
        sum[a][b]=min(aste,4-aste);
        cout << canti << "\n";
    }
}