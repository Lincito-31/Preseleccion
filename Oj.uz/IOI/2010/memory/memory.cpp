#include "grader.h"
#include "memory.h"
#include <bits/stdc++.h>
using namespace std;
void play() {
   int i;
   vector<pair<int,int>> resp(25);
   for(int i=1;i<=50;i++){
      char a=faceup(i);
      if(resp[a-65].first==0){
         resp[a-65].first=i;
      }else{
         resp[a-65].second=i;
      }
   }
   for(int i=0;i<25;i++){
      faceup(resp[i].first);
      faceup(resp[i].second);
   }
}
