#include <bits/stdc++.h>
using namespace std;
string x,y;
int n;
vector<int> psum,cantiAa,cantiAb;
void init(string a,string b){
	x=a;y=b;
	n=a.size(); 
	psum.resize(n+1);
	cantiAa.resize(n+1);
	cantiAb.resize(n+1);
	for(int i=1;i<=n;i++){
		cantiAa[i]=cantiAa[i-1]+(a[i-1]=='A');
		cantiAb[i]=cantiAb[i-1]+(b[i-1]=='A');
		psum[i]=psum[i-1]+(a[i-1]!=b[i-1]);
        //cout << cantiAa[i] << " " << cantiAb[i] << " " << psum[i] << endl;
	}
}

int get_distance(int x, int y){
	if(cantiAa[y+1]-cantiAa[x]==cantiAb[y+1]-cantiAb[x]){
        return (psum[y+1]-psum[x])>>1;
    }else{
        return -1;
    }
}

int main() {
	int n, q;
	assert(scanf("%d %d", &n, &q) == 2);
	char A[n+1], B[n+1];
	assert(scanf("%s", A) == 1);
	assert(scanf("%s", B) == 1);
	std::string a = std::string(A);
	std::string b = std::string(B);
	std::vector<int> x(q), y(q);
	for (int i = 0; i < q; i++) {
		assert(scanf("%d %d", &x[i], &y[i]) == 2);
	}
	fclose(stdin);
	std::vector<int> results(q);
	init(a, b);
	for (int i = 0; i < q; i++) {
		results[i] = get_distance(x[i], y[i]);
	}
	for (int i = 0; i < q; i++) {
		printf("%d\n", results[i]);
	}
	fclose(stdout);
	return 0;
}
