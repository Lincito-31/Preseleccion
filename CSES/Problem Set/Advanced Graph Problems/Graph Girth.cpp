#include <bits/stdc++.h>
using namespace std;
typedef vector<int> vi;
int n,m,a,b;
vector<int> graph[2500];
int mini=1e9,limi=1e8;
int main(){
    scanf("%d%d",&n,&m);
    while(m--){
        scanf("%d%d",&a,&b);
        a--;b--;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }
    for(int i=0;i<n;i++){
        vector<int> lon(n,-1);
        queue<vi> bfs;
        bfs.push({i,0,1});
        while(!bfs.empty()){
            int now=bfs.front()[0];
            int ante=bfs.front()[1];
            int longit=bfs.front()[2];
            bfs.pop();
            if(lon[now]!=-1){
                mini=min(mini,lon[now]+longit-2);
                limi=mini/2+5;
                if(longit>limi){
                    break;
                }
            }else{
                lon[now]=longit;
                for(auto u:graph[now]){
                    if(u==ante){
                        continue;
                    }
                    bfs.push({u,now,longit+1});
                }
            }
        }
    }
    if(mini==1e9){
        printf("-1");
    }else{
        printf("%d",mini);
    }
}