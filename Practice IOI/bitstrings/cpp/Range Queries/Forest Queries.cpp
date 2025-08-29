#include <bits/stdc++.h>
using namespace std;
int N,Q,u,d,l,r;
int psum[2001][2001];
char c;
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin >> N >> Q;
    for(int i=1;i<=N;i++){
        for(int j=1;j<=N;j++){
            cin >> c;
            psum[i][j]=psum[i-1][j]+psum[i][j-1]-psum[i-1][j-1]+(c=='*');
        }
    }
    while(Q--){
        cin >> u >> l >> d >> r;
        cout << psum[d][r]-psum[d][l-1]-psum[u-1][r]+psum[u-1][l-1] << '\n';
    }
}