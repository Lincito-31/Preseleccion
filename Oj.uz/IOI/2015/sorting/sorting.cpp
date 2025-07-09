#include "sorting.h"
#include <bits/stdc++.h>
using namespace std;
int findSwapPairs(int N, int S[], int M, int X[], int Y[], int P[], int Q[]){
	int now=0;
    for(int i=0;i<N;i++){
		for(int j=0;j<N;j++){
			if(S[j]==i){
				P[now]=i;
				Q[now]=j;
				swap(S[i],S[j]);
				now++;
				break;
			}
		}
	}
	return now;
}