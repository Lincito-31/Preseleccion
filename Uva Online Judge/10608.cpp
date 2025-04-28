#include <bits/stdc++.h>
using namespace std;
int t,n,m,a,b,res=1;
int dju[30005],tam[30005];
bool xd=false;
int find(int x){
    if(x==dju[x]){
        return x;
    }
    return dju[x]=find(dju[x]);
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
    tam[y]+=tam[x];
    dju[x]=y;
    res=max(res,tam[y]);
}
int main(){
    scanf("%d",&t);
    while(t--){
        res=1;
        scanf("%d%d",&n,&m);
        for(int i=0;i<=n;i++){
            dju[i]=i;
            tam[i]=1;
        }
        while(m--){
            scanf("%d%d",&a,&b);
            unite(a,b);
        }
        printf("%d\n",res);
    }
}