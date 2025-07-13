#include "fish.h"
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll mat[305][305],psum[305][305],dp[305][305],par,impar,dptask3[100002],vectask3[100002],miniz;
bool task1=true,task2=true,task3=true;
ll max_weights(int N,int M,vector<int> X,vector<int> Y,vector<int> W){
  for(int i=0;i<M;i++){
    if(X[i]%2){
      task1=false;
    }
    if(X[i]==0){
        if(Y[i]<Y[miniz]){
            miniz=i;
        }
      par+=W[i];
    }else{
      impar+=W[i];
    }
    if(X[i]>1){
      task2=false;
    }
    if(Y[i]!=0){
      task3=false;
    }
    vectask3[X[i]+1]=W[i];
  }
  if(task1){
    return par+impar;
  }else if(task2){
    if(N>2){
        return max(max(par,impar),impar+W[miniz]);
    }
    return max(par,impar);
  }else if(task3){
    for(int i=1;i<=N;i++){
      dptask3[i]=dptask3[i-1];
      dptask3[i]=max(dptask3[i],dptask3[i-1]-vectask3[i]+vectask3[i+1]);
      if(i>=2){
        dptask3[i]=max(dptask3[i],dptask3[i-2]+vectask3[i+1]);
      }
    }
    return dptask3[N];
  }
}


int main() {
  int N, M;
  assert(2 == scanf("%d %d", &N, &M));

  std::vector<int> X(M), Y(M), W(M);
  for (int i = 0; i < M; ++i) {
    assert(3 == scanf("%d %d %d", &X[i], &Y[i], &W[i]));
  }

  long long result = max_weights(N, M, X, Y, W);
  printf("%lld\n", result);
  return 0;
}
