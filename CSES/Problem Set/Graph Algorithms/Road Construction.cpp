#include <bits/stdc++.h>
#define ALL(x) x.begin(),x.end()
#define REV(x) x.rbegin(),x.rend()
using namespace std;
typedef long long ll;
int n,q,dsu[100000],tam[100000],a,b,maxi,con;
int find(int x){return x==dsu[x]?x:dsu[x]=find(dsu[x]);}
void unite(int x,int y){
    if((x=find(x))==(y=find(y))){
        return;
    }
    if(tam[x]>tam[y]){
        swap(x,y);
    }
    tam[y]+=tam[x];
    maxi=max(maxi,tam[y]);
    dsu[x]=y;
    con--;
}
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin >> n >> q;
    con=n;
    for(int i=0;i<n;i++){
        dsu[i]=i;
        tam[i]=1;
    }
    while(q--){
        cin >> a >> b;
        unite(--a,--b);
        cout << con << ' ' << maxi << '\n';
    }
}