#include <vector>
#include <bits/stdc++.h>
using namespace std;
int contador[1000001],cantimayores[1000001],sum;
vector<int> portales_accesibles(int N, int K, vector<int> H){
  vector<int> result(N);
  for(int i=0;i<N;i++){
    contador[H[i]]++;
  }
  for(int i=1e6;i>=0;i--){
    cantimayores[i]=sum;
    sum+=contador[i];
  }
  for(int i=0;i<N;i++){
    int now=H[i]-K;
    if(now==0){
      result[i]=cantimayores[K];
      continue;
    }
    if(now<=1){
      continue;
    }
    if(now%2==1){
      for(int j=1;j*j<=now;j+=2){
        if(now%j==0){
          if(j>K){
            result[i]+=contador[j];
          }
          if(j*j!=now){
            if(now/j>K){
              result[i]+=contador[now/j];
            }
          }
        }
      }
    }else{
      for(int j=1;j*j<=now;j++){
        if(now%j==0){
          if(j>K){
            result[i]+=contador[j];
          }
          if(j*j!=now){
            if(now/j>K){
              result[i]+=contador[now/j];
            }
          }
        }
      }
    }
    if(K==0){
      result[i]--;
    }
  }
  return result;
}