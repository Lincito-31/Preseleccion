#include "seats.h"
#include <bits/stdc++.h>
using namespace std;
vector<vector<int>> mat;
vector<pair<int,int>> pos_per;
int n,m,con;
void give_initial_chart(int H,int W,vector<int> R,vector<int> C){
  mat.assign(n=H,vector<int>(m=W));
  pos_per.resize(m*n);
  for(int i=0;i<H*W;i++){
    mat[R[i]][C[i]]=i;
    pos_per[i]={R[i],C[i]};
  }
}
int swap_seats(int a,int b){
  a--;b--;
  con=0;
  int botom=-1e9,top=1e9,left=1e9,right=-1e9;
  swap(mat[pos_per[a].first][pos_per[a].second],mat[pos_per[b].first][pos_per[b].second]);
  swap(pos_per[a],pos_per[b]);
  for(int i=0;i<n*m;i++){
    botom=max(botom,pos_per[i].first);
    top=min(top,pos_per[i].first);
    left=min(botom,pos_per[i].second);
    right=max(botom,pos_per[i].second);
    if((i+1)==(right-left+1)*(botom-top+1)){
      con++;
    }
  }
}
