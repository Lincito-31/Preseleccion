#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#define ALL(x) x.begin(),x.end()
using namespace std;
using namespace __gnu_pbds;
typedef long long ll;
typedef tree<int,null_type,less<int>,rb_tree_tag,tree_order_statistics_node_update> intset;
int n,m,q,a;
int main(){
    scanf("%d%d%d",&n,&m,&q);
    vector<int> repre(n);
    vector<bool> visited(n,false);
    if(m==0){
        intset cola;
        for(int i=0;i<n;i++){
            repre[i]=i;
            cola.insert(i);
        }
        ll cont=0,nue=-1;
        while(q--){
            scanf("%d",&a);
            a--;
            cont+=(ll)cola.order_of_key(repre[a])+1ll;
            cola.erase(repre[a]);
            repre[a]=nue;
            cola.insert(nue);
            nue--;
        }
        printf("%lld",cont);
    }else if(m==n){
        intset cola;
        for(int i=0;i<n;i++){
            repre[i]=i;
            cola.insert(i);
        }
        ll cont=0,nue=-1;
        while(q--){
            scanf("%d",&a);
            a--;
            if(visited[a]){
                continue;
            }
            visited[a]=true;
            cont+=(ll)cola.order_of_key(a)+1ll;
            cola.erase(a);
        }
        printf("%lld",cont);
    }else{
        
    }
}