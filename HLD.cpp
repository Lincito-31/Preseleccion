#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;
using namespace std;
typedef tree<int,null_type,less<int>,rb_tree_tag,tree_order_statistics_node_update> intset;
int n,a,b,q,t;
vector<int> graph[200000];
int tam[200000],pos[200000],padre[200000],alt[200000],chaincolor[200000],chainhead[200000],st[800000],arr[200000],tobeused[200000];
int chainNo=0,ptr=0;
void build(int node,int l,int r){
    if(l==r){
        st[node]=tobeused[l];
        return;
    }
    int mid=(l+r)>>1;
    int hiji=(node<<1)+1,hijd=(node<<1)+2;
    build(hiji,l,mid);
    build(hijd,mid+1,r);
    st[node]=max(st[hiji],st[hijd]);
}
void update(int node,int l,int r,int pos,int val){
    if(l==r){
        st[node]=val;
        return;
    }
    int mid=(l+r)>>1;
    int hiji=(node<<1)+1,hijd=(node<<1)+2;
    if(pos<=mid){
        update(hiji,l,mid,pos,val);
    }else{
        update(hijd,mid+1,r,pos,val);
    }
    st[node]=max(st[hiji],st[hijd]);
}
int query(int node,int l,int r,int i,int j){
    if(r<i || j<l){
        return -1;
    }
    if(i<=l && r<=j){
        return st[node];
    }
    int mid=(l+r)>>1;
    int hiji=(node<<1)+1,hijd=(node<<1)+2;
    return max(query(hiji,l,mid,i,j),query(hijd,mid+1,r,i,j));
}
int path(int x,int y){
    int res=-1;
    while(chaincolor[x]!=chaincolor[y]){
        if(alt[chainhead[chaincolor[y]]]<alt[chainhead[chaincolor[x]]]){
            swap(x,y);
        }
        res=max(res,query(0,0,n-1,pos[chainhead[chaincolor[y]]],pos[y]));
        y=padre[chainhead[chaincolor[y]]];
    }
    return res=max(res,query(0,0,n-1,min(pos[x],pos[y]),max(pos[x],pos[y])));
}
void hld(int now,int ante){
    pos[now]=ptr++;
    tobeused[ptr-1]=arr[now];
    if(chainhead[chainNo]==-1){
        chainhead[chainNo]=now;
    }
    chaincolor[now]=chainNo;
    int maxi=0,heavy=-1;
    for(auto u:graph[now]){
        if(u==ante){
            continue;
        }
        if(tam[u]>maxi){
            maxi=tam[u];
            heavy=u;
        }
    }
    if(heavy==-1){
        return;
    }
    hld(heavy,now);
    for(auto u:graph[now]){
        if(u==ante || u==heavy){
            continue;
        }
        chainNo++;
        hld(u,now);
    }
}
void dfs(int now,int ante){
    tam[now]=1;
    for(auto u:graph[now]){
        if(u==ante){
            continue;
        }
        padre[u]=now;
        alt[u]=alt[now]+1;
        dfs(u,now);
        tam[now]+=tam[u];
    }
}
int main(){
    scanf("%d%d",&n,&q);
    for(int i=0;i<n;i++){
        scanf("%d",&arr[i]);
        padre[i]=tam[i]=alt[i]=chainhead[i]=chaincolor[i]=-1;
    }
    for(int i=1;i<n;i++){
        scanf("%d%d",&a,&b);
        graph[--a].push_back(--b);
        graph[b].push_back(a);
    }
    padre[0]=-1;
    alt[0]=0;
    dfs(0,-1);
    hld(0,-1);
    build(0,0,n-1);
    while(q--){
        scanf("%d%d%d",&t,&a,&b);
        if(t==1){
            update(0,0,n-1,pos[--a],b);
        }else{
            printf("%d ",path(--a,--b));
        }
    }
}