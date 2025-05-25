#include <bits/stdc++.h>
using namespace std;
int n;
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin >> n;
    vector<vector<int>> board(n,vector<int>(n,0));
    queue<pair<int,int>> q;
    vector<pair<int,int>> moves={{-1,-2},{-1,2},{1,-2},{1,2},{-2,-1},{-2,1},{2,-1},{2,1}};
    q.push({0,0});
    while(!q.empty()){
        pair<int,int> top=q.front();
        q.pop();
        for(int i=0;i<8;i++){
            if(top.first+moves[i].first<0 || top.first+moves[i].first>=n || top.second+moves[i].second<0 || top.second+moves[i].second>=n){
                continue;
            }
            if(board[top.first+moves[i].first][top.second+moves[i].second]==0){
                board[top.first+moves[i].first][top.second+moves[i].second]=board[top.first][top.second]+1;
                q.push({top.first+moves[i].first,top.second+moves[i].second});
            }
        }
    }
    board[0][0]=0;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cout << board[i][j] << " \n"[j==n-1];
        }
    }
}