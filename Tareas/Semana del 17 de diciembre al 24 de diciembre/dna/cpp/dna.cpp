#include "dna.h"
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
	}
}

int get_distance(int x, int y){
	if(cantiAa[y+1]-cantiAa[x]==cantiAb[y+1]-cantiAb[x]){
        return (psum[y+1]-psum[x])>>1;
    }else{
        return -1;
    }
}
