#include <bits/stdc++.h>
#define LsOne(a) (a)&(-a)
using namespace std;
int N,Q,u,a,b,e,d;
int psum[2001][2001];
char c;
struct BIT2D{
    int n,m;
    vector<vector<int>> fenwick;
    void update(int x,int y,int val){
        int yy;
        while(x<=n){
            yy=y;
            while(yy<=m){
                fenwick[x][yy]+=val;
                yy+=LsOne(yy);
            }
            x+=LsOne(x);
        }
    }
    int sum(int x,int y){
        int suma=0;
        int yy;
        while(x>0){
            yy=y;
            while(yy>0){
                suma+=fenwick[x][yy];
                yy-=((yy)&(-yy));
            }
            x-=LsOne(x);
        }
        return suma;
    }
    int query(int xx1,int yy1,int xx2,int yy2){
        return sum(xx2,yy2)-sum(xx1-1,yy2)-sum(xx2,yy1-1)+sum(xx1-1,yy1-1);
    }
    BIT2D(int N,int M){
        n=N+2;
        m=M+2;
        fenwick.assign(n+2,vector<int>(m+2));
    }
};
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin >> N >> Q;
    BIT2D sol(N,N);
    for(int i=1;i<=N;i++){
        for(int j=1;j<=N;j++){
            cin >> c;
            psum[i][j]=(c=='*');
            if(c=='*'){
                sol.update(i,j,1);
            }
        }
    }
    while(Q--){
        cin >> u;
        if(u==1){
            cin >> a >> b;
            if(psum[a][b]){
                psum[a][b]=0;
                sol.update(a,b,-1);
            }else{
                psum[a][b]=1;
                sol.update(a,b,1);
            }
        }else{
            cin >> a >> b >> e >> d;
            cout << sol.query(a,b,e,d) << '\n';
        }
    }
}