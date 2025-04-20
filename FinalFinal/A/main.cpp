#include <bits/stdc++.h>
using namespace std;
#define ALL(x) x.begin(),x.end()
using namespace std;
const int MAXN=2e5;
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
	if(x==-1){
		return 0;
	}
	maxi=max(maxi,psumcanti[x]);
	for(int i=N-1;K>=0;i--){
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

int main() {

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);


	int n, k;
	cin>>n>>k;
	assert(n > 0 && n <= MAXN && k >= 0);

	vector<int> meat(n);
	for(auto &v:meat){
		int a; cin>>a;
		assert(0<=a && a<=9);
		v=a;
	}

	int res = max_meat(n, k, meat);


	cout << res << '\n';
	return 0;
}