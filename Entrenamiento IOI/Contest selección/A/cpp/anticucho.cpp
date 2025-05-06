#include "anticucho.h"
#include <vector>
#include <bits/stdc++.h>
#define ALL(x) x.begin(),x.end()
using namespace std;
vector<int> psumcanti,psumsuma;
int maxi=0,now=0;
int max_meat(int N, int K, std::vector<int> A){
	psumcanti.resize(N);
	psumsuma.resize(N);
	psumsuma[0]=A[0];
	if(A[0]==0){
		psumcanti[0]=1;
	}
	for(int i=1;i<N;i++){
		psumcanti[i]=psumcanti[i-1];
		if(A[i]==0){
			psumcanti[i]++;
		}
		psumsuma[i]=psumsuma[i-1]+A[i];
	}
	if(psumsuma[N-1]<=K){
		return psumcanti[N-1];
	}
	int x=upper_bound(ALL(psumsuma),K)-psumsuma.begin();
	x--;
	if(x!=-1){
		maxi=max(maxi,psumcanti[x]);
	}
	for(int i=N-1;K-A[i]>=0;i--){
		K-=A[i];
		if(A[i]==0){
			now++;
		}
		int x=upper_bound(ALL(psumsuma),K)-psumsuma.begin();
		x--;
		if(x==-1){
			maxi=max(maxi,now);
		}else{
			maxi=max(maxi,now+psumcanti[x]);
		}
	}
	return maxi;
}
