#include <bits/stdc++.h>
#define ALL(x) x.begin(),x.end()
#define REV(x) x.rbegin(),x.rend()
using namespace std;
typedef long long ll;
int n,q,dsu[100000],tam[100000],a,b,con,c;
ll maxi;
int find(int x){return x==dsu[x]?x:dsu[x]=find(dsu[x]);}
bool unite(int x,int y){
    if((x=find(x))==(y=find(y))){
        return false;
    }
    if(tam[x]>tam[y]){
        swap(x,y);
    }
    tam[y]+=tam[x];
    dsu[x]=y;
    con--;
    return true;
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
    vector<vector<int>> road(q);
    for(int i=0;i<q;i++){
        cin >> a >> b >> c;
        road[i]={c,--a,--b};
    }
    sort(ALL(road));
    for(int i=0;i<q;i++){
        if(unite(road[i][1],road[i][2])){
            maxi+=road[i][0];
            if(con==1){
                break;
            }
        }
    }
    if(con==1){
        cout << maxi;
    }else{
        cout << "IMPOSSIBLE";
    }
}