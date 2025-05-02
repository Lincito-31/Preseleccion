#include <bits/stdc++.h>
#define ALL(x) x.begin(),x.end()
using namespace std;
int a,b,con;
bool xd;
char c;
int mat[102][102],nue[102][102];
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    while(cin >> a >> b,a&&b){
        if(xd){
            cout << '\n';
        }
        xd=true;
        cout << "Field #" << ++con << ":\n";
        memset(mat,false,sizeof mat);
        memset(nue,0,sizeof nue);
        for(int i=1;i<=a;i++){
            for(int j=1;j<=b;j++){
                cin >> c;
                if(c=='*'){
                    mat[i][j]=true;
                    for(int k=i-1;k<=i+1;k++){
                        for(int l=j-1;l<=j+1;l++){
                            nue[k][l]++;
                        }
                    }
                    nue[i][j]--;
                }
            }
        }
        for(int i=1;i<=a;i++){
            for(int j=1;j<=b;j++){
                if(mat[i][j]){
                    cout << '*';
                }else{
                    cout << nue[i][j];
                }
            }
            cout << '\n';
        }
    }
}