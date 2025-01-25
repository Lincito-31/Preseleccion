#include <bits/stdc++.h>
using namespace std;
int n,m,r,c;
char tip;
int main(){
    scanf("%d%d",&n,&m);
    vector<vector<bool>> posi(n,vector<bool>(n+10,true));
    vector<bool> col(n+10,true),row(n+10,true),diag1(3*n-1,true),diag2(3*n-1,true);
    while(m--){
        scanf(" %c%d%d",&tip,&r,&c);
        r--;c--;
        if(tip=='R'){
            row[r]=false;
            col[c]=false;
        }else if(tip=='N'){
            posi[r][c]=false;
            if(r-2>=0 && c-1>=0){
                posi[r-2][c-1]=false;
            }
            if(r-1>=0 && c-2>=0){
                posi[r-1][c-2]=false;
            }
            if(r+2<n && c-1>=0){
                posi[r+2][c-1]=false;
            }
            if(r+1<n && c-2>=0){
                posi[r+1][c-2]=false;
            }
            if(r-2>=0 && c+1<n){
                posi[r-2][c+1]=false;
            }
            if(r-1>=0 && c+2<n){
                posi[r-1][c+2]=false;
            }
            if(r+2<n && c+1<n){
                posi[r+2][c+1]=false;
            }
            if(r+1<n && c+2<n){
                posi[r+1][c+2]=false;
            }
        }else{
            row[r]=false;
            col[c]=false;
            diag1[r+c]=false;
            diag2[r-c+n]=false;
        }
    }
    int con=0;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(row[i] && col[j] && diag1[i+j] && diag2[i-j+n] && posi[i][j]){
                con++;
            }
        }
    }
    con=n*n-con;
    printf("%d",con);
}