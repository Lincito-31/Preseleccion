#include <bits/stdc++.h>
using namespace std;
int n,a,b,dsu[10000],tam[10000];
int find(int x){
    if(x==dsu[x]){
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
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        dsu[i]=i;
        tam[i]=1;
    }
    vector<pair<int,int>> no;
    for(int i=1;i<n;i++){
        scanf("%d%d",&a,&b);
        if(!unite(--a,--b)){
            no.push_back({a,b});
        }
    }
    int con=0;
    printf("%d\n",no.size());
    for(int i=0;i<n;i++){
        if(unite(0,i)){
            printf("%d %d %d %d\n",no[con].first+1,no[con].second+1,1,i+1);
            con++;
        }
    }
}