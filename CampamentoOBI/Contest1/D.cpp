#include <bits/stdc++.h>
using namespace std;
int n,m,a,b;
vector<int> dsu,tam;
int find(int x){
    if(dsu[x]==x){
        return x;
    }
    return dsu[x]=find(dsu[x]);
}
void unite(int x,int y){
    x=find(x);y=find(y);
    if(x==y){
        return;
    }
    n--;
    if(tam[x]<tam[y]){
        swap(x,y);
    }
    dsu[y]=x;
    tam[x]+=tam[y];
}
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin >> n >> m;
    dsu.resize(n);
    tam.assign(n,1);
    for(int i=0;i<n;i++){
        dsu[i]=i;
    }
    while(m--){
        cin >> a >> b;
        unite(--a,--b);
    }
    cout << n-1;
}