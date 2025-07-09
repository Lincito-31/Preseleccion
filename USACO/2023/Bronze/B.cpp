#include <bits/stdc++.h>
#define ALL(x) x.begin(),x.end()
using namespace std;
int n,m,a,b,c,d,mini=1e9;
vector<int> air[10];
int stall[100];
int main(){
    cin >> n >> m;
    for(int i=0;i<n;i++){
        cin >> a >> b >> c;
        a--;
        b--;
        for(int j=a;j<=b;j++){
            stall[j]+=c;
        }
    }
    for(int i=0;i<m;i++){
        cin >> a >> b >> c >> d;
        air[i]={--a,--b,c,d};
    }
    for(int i=0;i<(1<<m);i++){
        int cost=0;
        for(int j=0;j<m;j++){
            if(i&(1<<j)){
                cost+=air[j][3];
                for(int k=air[j][0];k<=air[j][1];k++){
                    stall[k]-=air[j][2];
                }
            }
        }
        bool xd=true;
        for(int j=0;j<100;j++){
            if(stall[j]>0){
                xd=false;
                break;
            }
        }
        if(xd){
            mini=min(mini,cost);
        }
        for(int j=0;j<m;j++){
            if(i&(1<<j)){
                for(int k=air[j][0];k<=air[j][1];k++){
                    stall[k]+=air[j][2];
                }
            }
        }
    }
    cout << mini;
}