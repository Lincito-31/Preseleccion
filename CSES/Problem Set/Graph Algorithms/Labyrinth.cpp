#include <bits/stdc++.h>
using namespace std;
int Ax,Ay,n,m,Bx,By;
char mat[1000][1000];
pair<int,int> pad[1000][1000];
int main(){
    ios_base::sync_with_stdio(false);
    cout.tie(NULL);cin.tie(NULL);
    cin >> n >> m;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin >> mat[i][j];
            if(mat[i][j]=='A'){
                Ax=i;
                Ay=j;
            }
            if(mat[i][j]=='B'){
                Bx=i;
                By=j;
            }
            pad[i][j]={-1,-1};
        }
    }
    queue<pair<int,int>> cola;
    cola.push({Ax,Ay});
    while(!cola.empty()){
        pair<int,int> a=cola.front();cola.pop();
        int x=a.first,y=a.second;
        if(x>=n || x<0 || y>=m || y<0){
            continue;
        }
        if(mat[x][y]=='#'){
            continue;
        }
        if(mat[x][y]=='B'){
            break;
        }
        mat[x][y]='#';
        if(x<n-1){
            if(mat[x+1][y]!='#'){
                if(pad[x+1][y].first==-1){
                    pad[x+1][y]={x,y};
                    cola.push({x+1,y});
                }
            }
        }
        if(x>0){
            if(mat[x-1][y]!='#'){
                if(pad[x-1][y].first==-1){
                    pad[x-1][y]={x,y};
                    cola.push({x-1,y});
                }
            }
        }
        if(y<m-1){
            if(mat[x][y+1]!='#'){
                if(pad[x][y+1].first==-1){
                    pad[x][y+1]={x,y};
                    cola.push({x,y+1});
                }
            }
        }
        if(y>0){
            if(mat[x][y-1]!='#'){
                if(pad[x][y-1].first==-1){
                    pad[x][y-1]={x,y};
                    cola.push({x,y-1});
                }
            }
        }
    }
    if(pad[Bx][By].first==-1){
        cout << "NO";
    }else{
        int x=Bx,y=By;
        string st="";
        while(!(x==Ax&&y==Ay)){
            if(pad[x][y].first-x==1){
                st.push_back('L');
            }else if(pad[x][y].first-x==0){
                if(pad[x][y].first-y==1){
                    st.push_back('U');
                }else{
                    st.push_back('D');
                }
            }else{
                st.push_back('R');
            }
            int nuex=pad[x][y].first,nuey=pad[x][y].second;
            x=nuex;y=nuey;
        }
        //reverse(st.begin(),st.end());
        cout << "YES\n" << st.size() << "\n" << st;
    }
}