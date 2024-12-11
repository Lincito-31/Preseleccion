#include <bits/stdc++.h>
using namespace std;
typedef vector<int> vi;
int n,q,a,b;
int main(){
    scanf("%d%d",&n,&q);
    int boss[n],level[n];
    boss[0]=level[0]=0;
    vi graph[n];
    for(int i=1;i<n;i++){
        scanf("%d",&boss[i]);
        boss[i]--;
        graph[boss[i]].push_back(i);
    }
    queue<int> bfs;
    bfs.push(0);
    while(!bfs.empty()){
        int now=bfs.front();
        bfs.pop();
        for(auto u:graph[now]){
            level[u]=level[now]+1;
            bfs.push(u);
        }
    }

    int ancestor[n][18];
    for(int i=0;i<n;i++){
        ancestor[i][0]=boss[i];
    }
    for(int j=1;j<18;j++){
        for(int i=0;i<n;i++){
            ancestor[i][j]=ancestor[ancestor[i][j-1]][j-1];
        }
    }
    while(q--){
        scanf("%d%d",&a,&b);
        a--;b--;
        if(level[a]<level[b]){
            swap(a,b);
        }
        int cantianivelar=level[a]-level[b];
        for(int i=0;i<18;i++){
            if(cantianivelar&(1<<i)){
                a=ancestor[a][i];
            }
        }
        int l=0,r=level[a];
        while(l<r){
            int mid=(l+r)>>1;
            int aa=a,bb=b;;
            for(int i=0;i<18;i++){
                if(mid&(1<<i)){
                    aa=ancestor[aa][i];
                    bb=ancestor[bb][i];
                }
            }
            if(aa==bb){
                r=mid;
            }else{
                l=mid+1;
            }
        }
        for(int i=0;i<18;i++){
            if(l&(1<<i)){
                a=ancestor[a][i];
            }
        }
        printf("%d\n",a+1);
    }
}