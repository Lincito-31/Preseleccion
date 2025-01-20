#include <bits/stdc++.h>
using namespace std;
int n,m,d,a,b,c,res=0;
vector<pair<int,int>> graph[100000];
int main(){
    scanf("%d%d%d",&n,&m,&d);
    while(m--){
        scanf("%d%d%d",&a,&b,&c);
        a--;b--;
        if(a>b){
            swap(a,b);
        }
        graph[a].push_back({b,c});
    }
    int l=0,r=1e9+1;
    while(l<r){
        int mid=(l+r)>>1;
        vector<int> longitud(n,1e9);
        vector<bool> visited(n,false);
        queue<int> bfs;
        bfs.push(0);
        longitud[0]=0;
        visited[0]=true;
        while(!bfs.empty()){
            int top=bfs.front();
            bfs.pop();
            for(auto u:graph[top]){
                if(visited[u.first] || u.second>mid){
                    continue;
                }
                visited[u.first]=true;
                longitud[u.first]=longitud[top]+1;
                bfs.push(u.first);
            }
        }
        if(longitud[n-1]>d){
            l=mid+1;
        }else{
            r=mid;
        }
    }
    if(l==1e9+1){
        printf("-1");
    }else{
        vector<int> padre(n,1e9);
        vector<bool> visited(n,false);
        queue<int> bfs;
        bfs.push(0);
        padre[0]=0;
        visited[0]=true;
        while(!bfs.empty()){
            int top=bfs.front();
            bfs.pop();
            for(auto u:graph[top]){
                if(visited[u.first] || u.second>l){
                    continue;
                }
                visited[u.first]=true;
                padre[u.first]=top;
                bfs.push(u.first);
            }
        }
        int x=n-1;
        vector<int> respuesta;
        while(x!=0){
            respuesta.push_back(x);
            x=padre[x];
        }
        printf("%d\n",respuesta.size());
        printf("1 ");
        for(int i=respuesta.size()-1;i>=0;i--){
            printf("%d ",respuesta[i]+1);
        }
    }
}