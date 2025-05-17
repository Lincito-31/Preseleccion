#include <vector>
#include <bits/stdc++.h>
using namespace std;

int longitud_maxima(int N, int K, vector<int> A){
  int iz=0,maxi=0;
  map<int,int> contador;
  for(int i=0;i<N;i++){
    contador[A[i]]++;
    while(contador[A[i]]>K){
      contador[A[iz++]]--;
    }
    maxi=max(maxi,i-iz+1);
  }
  // CÓDIGO AQUÍ
  return maxi;
}
