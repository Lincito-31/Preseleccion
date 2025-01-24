#include <bits/stdc++.h>
using namespace std;
int n,m,a,b;
int dsu[100000],tam[100000];
int find(int x){
    if(dsu[x]==x){
        return x;
    }
    return dsu[x]=find(dsu[x]);
}
bool unite(int x,int y){
    x=find(x);
    y=find(y);
    if(x==y){
        return false;
    }
    if(tam[x]>tam[y]){
        swap(x,y);
    }
    dsu[x]=y;
    tam[y]+=tam[x];
    return true;
}
int main(){
    scanf("%d%d",&n,&m);
    for(int i=0;i<n;i++){
        dsu[i]=i;
        tam[i]=1;
    }
    while(m--){
        scanf("%d%d",&a,&b);
        unite(--a,--b);
    }
    vector<pair<int,int>> res;
    for(int i=0;i<n;i++){
        if(unite(0,i)){
            res.push_back({0,i});
        }
    }
    printf("%d\n",res.size());
    for(auto u:res){
        printf("%d %d\n",u.first+1,u.second+1);
    }
}