#include "quality.h"
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
using namespace std;
using namespace __gnu_pbds;
typedef tree<int,null_type,less<int>,rb_tree_tag,tree_order_statistics_node_update> intset;
int mini=1e9;
int help[3001][3001];
int rectangle(int R, int C, int H, int W, int Q[3001][3001]){
	int l=1,r=R*C;
	while(l<r){
		bool xd=false;
		for(int i=0;i<R;i++){
			for(int j=0;j<C;j++){
				help[i][j]=0;
			}
		}
		int mid=(l+r)>>1;
		for(int i=0;i<R;i++){
			for(int j=0;j<C;j++){
				if(Q[i][j]<=mid){
					help[max(i-H/2,0)][max(j-W/2,0)]++;
					help[max(i-H/2,0)][min(j+W/2+1,3000)]--;
					help[min(i+H/2+1,3000)][max(j-W/2,0)]--;
					help[min(i+H/2+1,3000)][min(j+W/2+1,3000)]++;
				}else{
					help[max(i-H/2,0)][max(j-W/2,0)]--;
					help[max(i-H/2,0)][min(j+W/2+1,3000)]++;
					help[min(i+H/2+1,3000)][max(j-W/2,0)]++;
					help[min(i+H/2+1,3000)][min(j+W/2+1,3000)]--;
				}
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
static int R,C,H,W,Q[3001][3001],i,j,ans;
int main(){
   scanf("%d%d%d%d",&R,&C,&H,&W);
   for (i=0;i<R;i++) for (j=0;j<C;j++) scanf("%d",&Q[i][j]);
   ans = rectangle(R,C,H,W,Q);
   printf("%d\n",ans);
   return 0;
}
