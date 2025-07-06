#include "quality.h"
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
using namespace std;
using namespace __gnu_pbds;
typedef tree<int,null_type,less<int>,rb_tree_tag,tree_order_statistics_node_update> intset;
int ca,help[3001][3001],l=1,r=9000000,mid;
bool xd;
int rectangle(int R, int C, int H, int W, int Q[3001][3001]){
	while(l<r){
		xd=false;
		for(int i=0;i<R;i++){
			for(int j=0;j<C;j++){
				help[i][j]=0;
			}
		}
		mid=(l+r)>>1;
		for(int i=0;i<R;i++){
			for(int j=0;j<C;j++){
				if(Q[i][j]<=mid){
					ca=1;
				}else{
					ca=-1;
				}
				help[max(i-H/2,0)][max(j-W/2,0)]+=ca;
				help[max(i-H/2,0)][min(j+W/2+1,3000)]-=ca;
				help[min(i+H/2+1,3000)][max(j-W/2,0)]-=ca;
				help[min(i+H/2+1,3000)][min(j+W/2+1,3000)]+=ca;
			}
		}
		for(int i=1;i<R;i++){
			help[i][0]+=help[i-1][0];
		}
		for(int i=1;i<C;i++){
			help[0][i]+=help[0][i-1];
		}
		for(int i=1;i<R;i++){
			for(int j=1;j<C;j++){
				help[i][j]+=help[i-1][j]+help[i][j-1]-help[i-1][j-1];
			}
		}
		for(int i=H/2;i<R-H/2 && !xd;i++){
			for(int j=W/2;j<C-W/2 && !xd;j++){
				if(help[i][j]>0){
					xd=true;
				}
			}
		}
		if(xd){
			r=mid;
		}else{
			l=mid+1;
		}
	}
	return l;
}