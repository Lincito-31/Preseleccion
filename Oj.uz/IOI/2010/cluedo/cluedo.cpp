#include "grader.h"
#include "cluedo.h"

void Solve(){
   int r,i=1,j=1,k=1;
   while(true){
      r=Theory(i,j,k);
      if(r==1){
         i++;
      }else if(r==2){
         j++;
      }else if(r==3){
         k++;
      }else{
         return;
      }
   }
}
