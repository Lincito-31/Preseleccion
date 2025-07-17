#include "mosaic.h"
#include <bits/stdc++.h>
#include <vector>
using namespace std;
typedef vector<int> vi;
typedef vector<long long> vll;
typedef long long ll;
int N,Q;
vll ans;
ll xpsum[3][200010],ypsum[3][200010],supercon[400010],supersum[400010],supersupersum[400010],supersupersumdere[400010];
vll mosaic(vi X, vi Y,vi T, vi B,vi L, vi R){
  ans.resize(Q=T.size());
  N=X.size();
  ll xlayer[3][N],ylayer[3][N];
  for(ll i=0;i<N;i++){
    xlayer[0][i]=X[i];
    ylayer[0][i]=Y[i];
  }
  xlayer[1][0]=ylayer[0][1];
  ylayer[1][0]=xlayer[0][1];
  // both 0 then 1
  for(ll i=1;i<N;i++){
    if(xlayer[1][i-1]==0 && xlayer[0][i]==0){
      xlayer[1][i]=1;
    }else{
      xlayer[1][i]=0;
    }
    if(ylayer[1][i-1]==0 && ylayer[0][i]==0){
      ylayer[1][i]=1;
    }else{
      ylayer[1][i]=0;
    }
  }
  xlayer[2][0]=ylayer[0][2];
  xlayer[2][1]=ylayer[1][2];
  ylayer[2][0]=xlayer[0][2];
  ylayer[2][1]=xlayer[1][2];
  for(ll i=2;i<N;i++){
    if(xlayer[2][i-1]==0 && xlayer[1][i]==0){
      xlayer[2][i]=1;
    }else{
      xlayer[2][i]=0;
    }
    if(ylayer[2][i-1]==0 && ylayer[1][i]==0){
      ylayer[2][i]=1;
    }else{
      ylayer[2][i]=0;
    }
  }
  for(ll i=0;i<3;i++){
    xpsum[i][0]=xlayer[i][0];
    ypsum[i][0]=ylayer[i][0];
    for(int j=1;j<N;j++){
      xpsum[i][j]=xlayer[i][j]+xpsum[i][j-1];
      ypsum[i][j]=ylayer[i][j]+ypsum[i][j-1];
    }
  }
  int con=0;
  // inicia con 3 termina con 2*N-2;
  for(ll i=N-1;i>=2;i--){
    supercon[2-i+N]=ylayer[2][i];
  }
  for(ll i=3;i<N;i++){
    supercon[i-2+N]=xlayer[2][i];
  }
  con=N+N-2;
  for(ll i=3;i<con;i++){
    supersum[i]=supersum[i-1]+supercon[i];
    supersupersum[i]=supersupersum[i-1]+(i-2)*supercon[i];
  }
  for(ll i=con-1;i>=3;i--){
    supersupersumdere[i]=supersupersumdere[i+1]+(con-i)*supercon[i];
  }
  for(ll i=0;i<Q;i++){
    if(T[i]==0){
      ans[i]+=xpsum[0][R[i]]-((L[i]-1==-1)?0:xpsum[0][L[i]-1]);
      T[i]++;
    }
    if(T[i]==1 && T[i]<=B[i]){
      ans[i]+=xpsum[1][R[i]]-((L[i]-1==-1)?0:xpsum[1][L[i]-1]);
      T[i]++;
    }
    if(T[i]>B[i]){
      continue;
    }
    if(L[i]==0){
      ans[i]+=ypsum[0][B[i]]-((T[i]-1==-1)?0:ypsum[0][T[i]-1]);
      L[i]++;
    }
    if(L[i]==1 &&   L[i]<=R[i]){
      ans[i]+=ypsum[1][B[i]]-((T[i]-1==-1)?0:ypsum[1][T[i]-1]);
      L[i]++;
    }
    if(L[i]>R[i]){
      continue;
    }
    /*
    mat[B[i]][L[i]] refeja en mat[B[i]-(min(B[i],L[i])-2)][L[i]-(min(B[i],L[i])-2)]
    mat[T[i]][R[i]] refleja en mat[T[i]-(min(T[i],R[i])-2)][R[i]-(min(T[i],R[i])-2)]
    habrá abs((R[i]-L[i]+1)-(B[i]-T[i]+1))+1 numeros cuya canti sea max. ese max=max(R[i]-L[i]+1,B[i]-T[i]+1);
    un mat[a][b] indica posicion b-a+N-2 en supercon
    => el primer bound es posicion 
    (L[i]-(min(B[i],L[i])-2))-(B[i]-(min(B[i],L[i])-2))-2+N;
    =L[i]-B[i]+N;
    y el ultimo bound es 
    R[i]-T[i]+N;
    bound:
    L[i]-B[i]-2+N.....L[i]-B[i]-3+N+max(R[i]-L[i],B[i]-T[i]) crece
    L[i]-B[i]-2+N+max(R[i]-L[i],B[i]-T[i])...L[i]-B[i]-2+N+2*max(R[i]-L[i],B[i]-T[i]) mantiene
    R[i]-T[i]-1+N-max(R[i]-L[i],B[i]-T[i])...R[i]-T[i]-2+N decrece
    */
    ll bound1=L[i]-B[i]+N;
    ll m=min(R[i]-L[i],B[i]-T[i])+1;
    ll k=abs(R[i]-L[i]-B[i]+T[i])+1;
    ll bound2=bound1+m-2;
    ll bound3=bound2+1;
    ll bound4=bound3+k-1;
    ll bound5=bound4+1;
    ll bound6=R[i]-T[i]+N;
    if(m==1){
      ans[i]+=supersum[bound6]-supersum[bound1-1];
      continue;
    }
    if(bound2>=bound1){
      ans[i]+=supersupersum[bound2]-supersupersum[bound1-1];
      ans[i]-=(bound1-3)*(supersum[bound2]-supersum[bound1-1]);
    }
    if(bound4>=bound3){
      ans[i]+=m*(supersum[bound4]-supersum[bound3-1]);
    }
    if(bound6>=bound5){
      ans[i]+=(supersupersumdere[bound5]-supersupersumdere[bound6+1]);
      ans[i]-=(bound1-3)*(supersum[bound6]-supersum[bound5-1]);
    }
  }
  return ans;
}
