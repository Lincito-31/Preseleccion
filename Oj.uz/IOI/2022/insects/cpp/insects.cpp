#include "insects.h"
#include <bits/stdc++.h>
#define ALL(x) x.begin(),x.end()
using namespace std;
bool dentro_de_maquina[2000];
int n,Indep,cant;
vector<int> last,ante;
int min_cardinality(int N){
  mt19937 rng(chrono::steady_clock().now().time_since_epoch().count());
  n=N;
  move_inside(0);
  dentro_de_maquina[0]=true;
  Indep++;
  cant++;
  for(int i=1;i<N;i++){
    move_inside(i);
    if(press_button()==1){
      dentro_de_maquina[i]=true;
      Indep++;
      cant++;
    }else{
      move_outside(i);
      ante.push_back(i);
    }
  }
  shuffle(ALL(ante),rng);
  int l=1,r=N/Indep;
  while(l<r){
    int mid=(l+r+1)>>1;
    last.clear();
    for(auto i:ante){
      if(cant==mid*Indep){
        break;
      }
      if(!dentro_de_maquina[i]){
        move_inside(i);
        if(press_button()<=mid){
          dentro_de_maquina[i]=true;
          cant++;
          last.push_back(i);
        }else{
          move_outside(i);
        }
      }
    }
    if(cant==Indep*mid){
      //ans>=mid;
      l=mid;
    }else{
      //ans<mid
      r=mid-1;
      for(auto u:last){
        move_outside(u);
        dentro_de_maquina[u]=false;
        cant--;
      }
      ante=last;
    }
  }
  return l;
}
