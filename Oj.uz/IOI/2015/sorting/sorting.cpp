#include "sorting.h"
#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pii;
int n;
vector<int> ss,x,y;
vector<pii> ans;
bool xd=true;
bool check(int m){
	ans.clear();
	vector<int> plate_sitting_in_pos(n),pos_of_apple(n),apple_sitting_in_pos(n),pos_of_plate(n);
	for(int i=0;i<n;i++){
		apple_sitting_in_pos[i]=ss[i];
		pos_of_apple[apple_sitting_in_pos[i]]=i;
		plate_sitting_in_pos[i]=i;
	}
	for(int i=0;i<m;i++){
		swap(plate_sitting_in_pos[x[i]],plate_sitting_in_pos[y[i]]);
		swap(apple_sitting_in_pos[x[i]],apple_sitting_in_pos[y[i]]);
		swap
	}
	for(int i=0;i<n;i++){
		pos_of_plate[plate_sitting_in_pos[i]]=i;
	}
	int p=0;
	for(int i=0;i<n;i++){
		//make pos_of_apple[i]==pos_of_plate[i]
		if(pos_of_apple[i]==pos_of_plate[i]){
			continue;
		}
		int aaa=pos_of_apple[i];
		//cout << "a";
		//cambiar el apple[pos_of_apple[i]] con apple[pos_of_plate[i]];
		ans.push_back({pos_of_apple[i],pos_of_plate[i]});
		int ante1=apple_sitting_in_pos[pos_of_apple[i]],ante2=apple_sitting_in_pos[pos_of_plate[i]];
		swap(apple_sitting_in_pos[pos_of_apple[i]],apple_sitting_in_pos[pos_of_plate[i]]);
		pos_of_apple[ante1]=pos_of_plate[i];
		pos_of_apple[ante2]=aaa;
		if(pos_of_apple[i]!=pos_of_plate[i]){
			cout << "b";
		}
		p++;
	}
	//cout << endl;
	while(p<m){
		p++;
		ans.push_back({0,0});
	}
	return (p==m);
}
int findSwapPairs(int N,int S[],int M,int X[],int Y[],int p[],int q[]){
	n=N;
	ss.assign(n,0);
	x.assign(M,0);
	y.assign(M,0);
	for(int i=0;i<n;i++){
		ss[i]=S[i];
	}
	for(int i=0;i<M;i++){
		x[i]=X[i];
		y[i]=Y[i];
	}
	int l=0,r=M;
	while(l<r){
		int mid=(l+r)>>1;
		if(check(mid)){
			r=mid;
		}else{
			l=mid+1;
		}
	}
	check(l);
	for(int i=0;i<l;i++){
		p[i]=ans[i].first;
		q[i]=ans[i].second;
	}
	return l;
}