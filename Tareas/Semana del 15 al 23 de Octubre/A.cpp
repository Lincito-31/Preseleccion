//https://www.codechef.com/LTIME91B/problems/HRSCPMTR
#include <bits/stdc++.h>
using namespace std;
int t,n,m,q,x,y,v;
int main(){
    scanf("%d",&t);
    while(t--){
        scanf("%d %d",&n,&m);
        vector<vector<int>> mat(n,vector<int>(m));
        vector<map<int,int>> diag(n+m-1);
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                scanf("%d",&mat[i][j]);
                diag[i-j+m-1][mat[i][j]]++;
            }
        }
        vector<bool> nose(n+m-1,false);
        int cant=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(diag[i-j+m-1][mat[i][j]]==min(n-i,m-j)+min(i,j)){
                    nose[i-j+m-1]=true;
                }
            }
        }
        for(int i=0;i<n+m;i++){
            if(nose[i]){
                cant++;
            }
        }
        scanf("%d",&q);
        while(q--){
            scanf("%d %d %d",&x,&y,&v);
            x--;y--;
            //printf("%d ",cant);
            diag[x-y+m-1][mat[x][y]]--;
            mat[x][y]=v;
            diag[x-y+m-1][mat[x][y]]++;
            if(nose[x-y+m-1]){
                nose[x-y+m-1]=false;
                cant--;
            }
            //cout << mat[x][y]  << " " << diag[x-y+m-1][mat[x][y]] << " " << min(n-x,m-y)+min(x,y);
            if(diag[x-y+m-1][mat[x][y]]==min(n-x,m-y)+min(x,y)){
                nose[x-y+m-1]=true;
                cant++;
            }
            //printf("%d ",cant);
            if(cant==n+m-1){
                printf("Yes\n");
            }else{
                printf("No\n");
            }
        }
    }
}