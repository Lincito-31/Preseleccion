#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#define MOD 1000000007
#define ALL(x) x.begin(),x.end()
#define REV(x) x.rbegin(),x.rend();
#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
using namespace std;
using namespace __gnu_pbds;
typedef long long ll;
typedef vector<int> vi;
typedef vector<long long> vll;
typedef pair<int,int> pii;
typedef pair<long long,long long> pll;
typedef tree<int,null_type,less<int>,rb_tree_tag,tree_order_statistics_node_update> indexed_set;
vector<int> visited;
vector<int> parent;
vector<int> dsu;
vector<int> lon;
int t=1,n,a;
int find(int x){
    if(x==dsu[x]){
        return x;
    }
    return dsu[x]=find(dsu[x]);
}
void unir(int x,int y){
    x=find(x);
    y=find(y);
    if(x==y){
        return;
    }
    dsu[x]=y;
}
void findciclo(int x){
    visited[x]++;
    if(visited[parent[x]]<=1){
        findciclo(parent[x]);
    }
}
int findlon(int x){
    if(lon[x]!=0){
        return lon[x];
    }
    return lon[x]=findlon(parent[x])+1;
}
int main(){
    scanf("%d",&t);
    while(t--){
        int maxi=0;
        scanf("%d",&n);
        visited.assign(n,0);
        parent.assign(n,0);
        dsu.assign(n,0);
        lon.assign(n,0);
        for(int i=0;i<n;i++){
            dsu[i]=i;
        }
        for(int i=0;i<n;i++){
            scanf("%d",&a);
            a--;
            parent[i]=a;
            unir(i,a);
        }
        vi comp;
        vector<bool> visitedcomp(n,false);
        for(int i=0;i<n;i++){
            int aaa=find(i);
            if(visitedcomp[aaa]){
                continue;
            }
            visitedcomp[aaa]=true;
            comp.push_back(aaa);
        }
        for(auto bb:comp){
            findciclo(bb);
        }
        for(int i=0;i<n;i++){
            if(visited[i]==2){
                lon[i]=2;
            }
        }
        for(int i=0;i<n;i++){
            maxi=max(findlon(i),maxi);
        }
        printf("%d\n",maxi);
    }
}