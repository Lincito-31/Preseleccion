#include <bits/stdc++.h>
using namespace std;
int n,m,a,b,c;
vector<int> dsu;
int find(int x){return x==dsu[x]?x:dsu[x]=find(dsu[x]);}
void unite(int x,int y){
    if((x=find(x))==(y=find(y))){
        return;
    }
    dsu[x]=y;
}
int main(){
    ifstream in("wormsort.in");
    ofstream out("wormsort.out");
    in >> n >> m;
    int pos[n];
    dsu.resize(n);
    for(int i=0;i<n;i++){
        in >> pos[i];
        dsu[i]=i;
        pos[i]--;
    }
    vector<int> worm[m];
    for(int i=0;i<m;i++){
        in >> a >> b >> c;
        worm[i]={c,--a,--b};
    }
    sort(worm,worm+m);
    int last=m;
    for(int i=0;i<n;i++){
        while(find(i)!=find(pos[i])){
            last--;
            unite(worm[last][1],worm[last][2]);
        }
    }
    if(last==m){
        out << -1;
    }else{
        out << worm[last][0];
    }
}