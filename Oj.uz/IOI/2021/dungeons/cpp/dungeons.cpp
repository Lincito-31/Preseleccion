#include "dungeons.h"
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<int> vi;
int N;
bool task2=true;
vector<vi> To;
vector<int> bjlosing[20],bjwining[20];
ll power,fuerza;
ll bigmod(ll b,ll e){
	ll p=1;
	while(e){
		if(e%2){
			p*=b;
		}
		b*=b;
		e/=2;
	}
	return p;
}
//strenth,losingstrength,winignto,losingto
void init(int n,vi s,vi p,vi w,vi l){
	N=n;
	To.resize(N+1);
	for(int i=0;i<20;i++){
		bjlosing[i].resize(N+1);
		bjwining[i].resize(N+1);
	}
	power=s[0];
	for(int i=0;i<N;i++){
		To[i]={s[i],p[i],w[i],l[i]};
		if(s[i]!=p[i]){
			task2=false;
		}
		bjlosing[0][i]=l[i];
		bjwining[0][i]=w[i];
	}
	bjlosing[0][N]=N;
	bjwining[0][N]=N;
	for(int i=1;i<20;i++){
		for(int j=0;j<=N;j++){
			bjlosing[i][j]=bjlosing[i-1][bjlosing[i-1][j]];
			bjwining[i][j]=bjwining[i-1][bjwining[i-1][j]];
		}
	}
	return;
}
ll simulate(int x,int z){
	fuerza=z;
	if(task2){
		if(fuerza<power){
			x=bjlosing[0][x];
			fuerza+=power;
		}
		if(x==N){
			return fuerza;
		}
		for(int i=20;i>=0;i--){
			if(bjwining[i][x]!=N){
				fuerza+=bigmod(2,i)*power;
				x=bjwining[i][x];
			}
		}
		fuerza+=power;
		x=bjwining[0][x];
	}else{
		while(x!=N){
			if(fuerza>=To[x][0]){
				fuerza+=To[x][0];
				x=To[x][2];
			}else{
				fuerza+=To[x][1];
				x=To[x][3];
			}
		}
	}
	return fuerza;
}