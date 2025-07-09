#include <bits/stdc++.h>
using namespace std;
int n,m,k,a,b,c;
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin >> n >> m >> k;
    vector<vector<int>> spiral(k);
    for(int i=0;i<k;i++){
        cin >> a >> b >> c;
        spiral[i]={--a,--b,c};
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            int mini=1e9;
            for(int l=0;l<k;l++){
                if(spiral[l][2]){
                    //counter
                    int x=max(abs(i-spiral[l][0]),abs(j-spiral[l][1]));
                    int len=2*x+1;
                    int val=len*len;
                    int posx=spiral[l][0]-x,posy=spiral[l][1]+x;
                    if(j==posy){
                        val-=abs(posx-i);
                    }else{
                        val-=len-1;
                        posx+=len-1;
                        if(posx==i){
                            val-=abs(posy-j);
                        }else{
                            val-=len-1;
                            posy-=len-1;
                            if(posy==j){
                                val-=abs(posx-i);
                            }else{
                                posx-=len-1;
                                val-=len-1;
                                val-=abs(posy-j);
                                posy=j;
                            }
                        }
                    }
                    mini=min(mini,val);
                }else{
                    //clock
                    int x=max(abs(i-spiral[l][0]),abs(j-spiral[l][1]));
                    int len=2*x+1;
                    int val=len*len;
                    int posx=spiral[l][0]-x,posy=spiral[l][1]-x;
                    if(j==posy){
                        val-=abs(posx-i);
                    }else{
                        val-=len-1;
                        posx+=len-1;
                        if(posx==i){
                            val-=abs(posy-j);
                        }else{
                            val-=len-1;
                            posy+=len-1;
                            if(posy==j){
                                val-=abs(posx-i);
                            }else{
                                posx-=len-1;
                                val-=len-1;
                                val-=abs(posy-j);
                                posy=j;
                            }
                        }
                    }
                    mini=min(mini,val);
                }
            }
            cout << mini << " \n"[j==m-1];
        }
    }
}