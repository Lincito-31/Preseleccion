#include <bits/stdc++.h>
using namespace std;
typedef vector<int> vi;
vi graph[200000];
int level[200000],ancestor[200000][18],padre[200000];
int n,q,a,b;
void dfs(int now,int ante){
    for(auto u:graph[now]){
        if(u==ante){
            continue;
        }
        padre[u]=now;
        level[u]=level[now]+1;
        dfs(u,now);
    }
}
int main(){
    scanf("%d%d",&n,&q);
    padre[0]=0;
    for(int i=1;i<n;i++){
        scanf("%d%d",&a,&b);
        a--;b--;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }
    dfs(0,-1);
    for(int i=0;i<n;i++){
        ancestor[i][0]=padre[i];
    }
    for(int j=1;j<18;j++){
        for(int i=0;i<n;i++){
            ancestor[i][j]=ancestor[ancestor[i][j-1]][j-1];
        }
    }
    while(q--){
        scanf("%d%d",&a,&b);
        a--;b--;
        int res=level[a]+level[b];
        if(level[a]<level[b]){
            swap(a,b);
        }
        int nivelar=level[a]-level[b];
        for(int i=0;i<18;i++){
            if(nivelar&(1<<i)){
                a=ancestor[a][i];
            }
        }
        int r=level[a];
        while(a!=b){
            int mid=r>>1;
            int aa=a,bb=b;
            for(int i=0;i<18;i++){
                if(mid&(1<<i)){
                    aa=ancestor[aa][i];
                    bb=ancestor[bb][i];
                }
            }
            if(aa==bb){
                r=mid;
            }else{
                a=ancestor[aa][0];
                b=ancestor[bb][0];
                r=level[a];
            }
        }
        /*for(int i=0;i<18;i++){
            if(l&(1<<i)){
                a=ancestor[a][i];
            }
        }*/
        res-=2*level[a];
        printf("%d\n",res);
    }
}