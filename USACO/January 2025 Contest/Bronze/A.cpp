#include <bits/stdc++.h>
using namespace std;
int t,n,a,b;
int main(){
    scanf("%d",&t);
    while(t--){
        scanf("%d%d%d",&n,&a,&b);
        char lon[n];
        vector<vector<int>> mat(n,vector<int>(n,0));
        for(int i=0;i<n;i++){
            scanf(" %s",lon);
            for(int j=0;j<n;j++){
                if(lon[j]=='B'){
                    mat[i][j]=2;
                }else if(lon[j]=='G'){
                    mat[i][j]=1;
                }else{
                    mat[i][j]=0;
                }
            }
        }
        bool xd=true;
        int con=0;
        vector<vector<bool>> existe(n,vector<bool>(n,false));
        for(int i=0;i<n && xd;i++){
            for(int j=0;j<n && xd;j++){
                if(mat[i][j]==2){
                    if(a==0 && b==0){
                        mat[i][j]=0;
                        existe[i][j]=true;
                        continue;
                    }
                    if(i-b>=0 && j-a>=0){
                        if(mat[i-b][j-a]==1 && !existe[i-b][j-a]){
                            mat[i-b][j-a]--;
                            existe[i-b][j-a]=true;
                            mat[i][j]--;
                        }else{
                            xd=false;
                        }
                    }else{
                        xd=false;
                    }
                }
            }
        }
        for(int i=0;i<n && xd;i++){
            for(int j=0;j<n && xd;j++){
                if(mat[i][j]==1){
                    existe[i][j]=true;
                    if(i+b<n && j+a<n){
                        if(mat[i+b][j+a]>0){
                            mat[i+b][j+a]--;
                        }
                    }
                }
            }
        }
        if(xd){
            for(int i=0;i<n;i++){
                for(int j=0;j<n;j++){
                    if(existe[i][j]){
                        con++;
                    }
                }
            }
            printf("%d\n",con);
        }else{
            printf("-1\n");
        }
    }
}