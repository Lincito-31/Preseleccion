#include "wall.h"
#include <bits/stdc++.h>
using namespace std;
void buildWall(int n, int k, int op[], int left[], int right[], int height[], int finalHeight[]){
  if(n<=10000 && k<=5000){
    for(int i=0;i<n;i++){
      finalHeight[i]=0;
    }
    for(int i=0;i<k;i++){
      for(int j=left[i];j<=right[i];j++){
        if(op[i]==1){
          finalHeight[j]=max(finalHeight[j],height[i]);
        }else{
          finalHeight[j]=min(finalHeight[j],height[i]);
        }
      }
    }
  }else{
    for(int i=0;i<n;i++){
      finalHeight[i]=0;
    }
    vector<vector<int>> add(n+1),remove(n+1);
    for(int i=0;i<k;i++){
      if(op[i]==1){
        add[left[i]].push_back(i);
        remove[right[i]+1].push_back(i);
      }
    }
    set<pair<int,int>> posi;
    posi.insert({0,-1});
    for(int i=0;i<n;i++){
      for(int j=0;j<add[i].size();j++){
        posi.insert({height[add[i][j]],add[i][j]});
      }
      for(int j=0;j<remove[i].size();j++){
        posi.erase({height[remove[i][j]],remove[i][j]});
      }
      auto p=posi.end();
      p--;
      finalHeight[i]=p->first;
    }
    add.clear();
    remove.clear();
    add.resize(n+1);
    remove.resize(n+1);
    for(int i=0;i<k;i++){
      if(op[i]==2){
        add[left[i]].push_back(i);
        remove[right[i]+1].push_back(i);
      }
    }
    posi.clear();
    posi.insert({1e9,-1});
    for(int i=0;i<n;i++){
      for(int j=0;j<add[i].size();j++){
        posi.insert({height[add[i][j]],add[i][j]});
      }
      for(int j=0;j<remove[i].size();j++){
        posi.erase({height[remove[i][j]],remove[i][j]});
      }
      auto p=posi.begin();
      finalHeight[i]=min(finalHeight[i],p->first);
    }
  }
  return;
}

