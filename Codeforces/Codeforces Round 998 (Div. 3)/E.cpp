#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#define MOD 1000000007
#define ALL(x) x.begin(),x.end()
#define REV(x) x.rbegin(),x.rend()
#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
using namespace __gnu_pbds;
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef vector<long long> vll;
typedef pair<int,int> pii;
typedef pair<long long,long long> pll;
typedef tree<int,null_type,less<int>,rb_tree_tag,tree_order_statistics_node_update> intset;
int t=1,n,m1,m2,a,b;
vi dju,dju2;
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
    dju[x]=y;
    return;
}

int find22(int x){
    if(x==dju2[x]){
        return x;
    }
    return dju2[x]=find22(dju2[x]);
}
void unite22(int x,int y){
    x=find22(x);
    y=find22(y);
    if(x==y){
        return;
    }
    dju2[x]=y;
    return;
}
int main(){
    scanf("%d",&t);
    while(t--){
        scanf("%d%d%d",&n,&m1,&m2);
        dju.resize(n);
        dju2.resize(n);
        for(int i=0;i<n;i++){
            dju[i]=i;
            dju2[i]=i;
        }
        vector<pii> edges,edges2;
        for(int i=0;i<m1;i++){
            scanf("%d%d",&a,&b);
            edges.push_back({--a,--b});
        }
        for(int i=0;i<m2;i++){
            scanf("%d%d",&a,&b);
            unite(--a,--b);
            edges2.push_back({a,b});
        }
        int remove=0;
        for(auto u:edges){
            if(find(u.first)!=find(u.second)){
                remove++;
                u.first=0;
                u.second=0;
            }
            unite22(u.first,u.second);
        }
        int unir=0;
        for(auto u:edges2){
            if(find22(u.first)!=find22(u.second)){
                unite22(u.first,u.second);
                unir++;
            }
        }
        printf("%d\n",remove+unir);
    }
}
