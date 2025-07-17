#include "elephants.h"
#include <bits/stdc++.h>
using namespace std;
int n,l;
vector<pair<int,int>> ele;
void init(int N,int L,int X[]){
  ele.resize(n=N);
  l=L;
  for(int i=0;i<n;i++){
    ele[i]={X[i],i};
  }
}
int update(int pos,int y){
  vector<pair<int,int>> nue;
  for(int j=0;j<n;j++){
    if(ele[j].second==pos){
      continue;
    }
    if(ele[j].first<y){
      nue.push_back(ele[j]);
    }else{
      nue.push_back({y,pos});
      for(;j<n;j++){
        if(ele[j].second==pos){
          continue;
        }
        nue.push_back(ele[j]);
      }
      break;
    }
  }
  if(nue.size()==n-1){
    nue.push_back({y,pos});
  }
  ele=nue;
  int last=-1-l,con=0;
  for(int i=0;i<n;i++){
    if(last+l<ele[i].first){
      last=ele[i].first;
      con++;
    }
  }
  return con;
}
