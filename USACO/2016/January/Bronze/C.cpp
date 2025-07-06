#include <bits/stdc++.h>
#define ALL(x) x.begin(),x.end()
using namespace std;
int n,num,maxi=1e9,now,gard[2001][2001],x=1000,y=1000;
char d;
int main(){
    ifstream in("mowing.in");
    ofstream out("mowing.out");
    in >> n;
    for(int i=0;i<2001;i++){
        for(int j=0;j<2001;j++){
            gard[i][j]=1e9;
        }
    }
    gard[x][y]=now++;
    while(n--){
        in >> d >> num;
        if(d=='N'){
            while(num--){
                if(gard[x][y-1]!=1e9){
                    maxi=min(maxi,now-gard[x][y-1]);
                }
                gard[x][--y]=now++;
            }
        }else if(d=='S'){
            while(num--){
                if(gard[x][y+1]!=1e9){
                    maxi=min(maxi,now-gard[x][y+1]);
                }
                gard[x][++y]=now++;
            }
        }else if(d=='W'){
            while(num--){
                if(gard[x-1][y]!=1e9){
                    maxi=min(maxi,now-gard[x-1][y]);
                }
                gard[--x][y]=now++;
            }
        }else{
            while(num--){
                if(gard[x+1][y]!=1e9){
                    maxi=min(maxi,now-gard[x+1][y]);
                }
                gard[++x][y]=now++;
            }
        }
    }
    out << ((maxi==1e9)?-1:maxi);
}