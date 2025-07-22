#include <bits/stdc++.h>
#define ALL(x) x.begin(),x.end()
#define REV(x) x.rbegin(),x.rend()
using namespace std;
typedef long long ll;
int n,q,dsu[200000],a,b,c;
int find(int x){return x==dsu[x]?x:dsu[x]=find(dsu[x]);}
void unite(int x,int y){
    if((x=find(x))==(y=find(y))){
        return;
    }
    dsu[x]=y;
}
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin >> n >> q;
    for(int i=0;i<n;i++){
        dsu[i]=i;
    }
    while(q--){
        cin >> c >> a >> b;
        if(c){
            cout << (find(a)==find(b)) << '\n';
        }else{
            unite(a,b);
        }
    }
}