#include <bits/stdc++.h>
using namespace std;
int n,m,dsu[150000],tam[150000],a,b,degree[150000];
int find(int x){
    if(x==dsu[x]){
        return x;
    }
    return dsu[x]=find(dsu[x]);
}
void unite(int x,int y){
    x=find(x);
    y=find(y);
    if(x==y){
        return;
    }
    if(tam[x]>tam[y]){
        swap(x,y);
    }
    dsu[x]=y;
    tam[y]+=tam[x];
    return;
}
int main(){
    scanf("%d%d",&n,&m);
    for(int i=0;i<n;i++){
        dsu[i]=i;
        tam[i]=1;
        degree[i]=0;
    }
    while(m--){
        scanf("%d%d",&a,&b);
        unite(--a,--b);
        degree[a]++;
        degree[b]++;
    }
    bool xd=true;
    for(int i=0;i<n;i++){
        if(degree[i]!=tam[find(i)]-1){
            xd=false;
        }
    }
    if(xd){
        printf("YES");
    }else{
        printf("NO");
    }
}