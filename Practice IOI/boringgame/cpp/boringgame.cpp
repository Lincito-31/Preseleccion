#include "boringgame.h"
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll l,r,mid,lastl,lastr,con,ininum;
bool ini_st;
ll play_game() {
  lastl=l=1;
  lastr=r=1e18;
  ininum=mid=(l+r+1)>>1;
  ini_st=ask(mid);
  if(ini_st){
    lastl=l=mid;
  }else{
    lastr=r=mid-1;
  }
  con=11;
  while(lastl<lastr){
    for(int i=0;i<con && l<r;i++){
      mid=(l+r+1)>>1;
      if(ask(mid)){
        l=mid;
      }else{
        r=mid-1;
      }
    }
    con--;
    if(ask(ininum)==ini_st){
      //sigue siendo verdad;
      lastl=l;
      lastr=r;
    }else{
      //ahora es mentira;
      while(lastl<lastr){
        mid=(lastl+lastr+1)>>1;
        if(ask(mid)){
          lastr=mid-1;
        }else{
          lastl=mid;
        }
      }
      break;
    }
  }
  return lastl;
}
