#include <bits/stdc++.h>
using namespace std;
int n,q,a,b,c;
vector<int> padre,altura,tam,pos,chaincolor,arr,chainhead,tobeused,st;
vector<vector<int>> graph;
int ColorNo=0,ptr=0;
void build(int node,int l,int r){
    if(l==r){
        st[node]=tobeused[l];
        return;
    }
    int hiji=(node<<1)+1,hijd=(node<<1)+2,mid=(l+r)>>1;
    build(hiji,l,mid);
    build(hijd,mid+1,r);
    st[node]=max(st[hiji],st[hijd]);
}
void update(int node,int l,int r,int pos,int val){
    if(l==r){
        st[node]=val;
        return;
    }
    int mid=(l+r)>>1,hiji=(node<<1)+1,hijd=(node<<1)+2;
    if(pos<=mid){
        update(hiji,l,mid,pos,val);
    }else{
        update(hijd,mid+1,r,pos,val);
    }
    st[node]=max(st[hiji],st[hijd]);
}
int query(int node,int l,int r,int i ,int j){
    if(r<i || j<l){
        return 0;
    }
    if(i<=l && r<=j){
        return st[node];
    }
    int mid=(l+r)>>1,hiji=(node<<1)+1,hijd=(node<<1)+2;
    return max(query(hiji,l,mid,i,j),query(hijd,mid+1,r,i,j));
}
int path(int x,int y){
    int res=0;
    while(chaincolor[x]!=chaincolor[y]){
        if(altura[chainhead[chaincolor[x]]]>altura[chainhead[chaincolor[y]]]){
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
    if(chainhead[ColorNo]==-1){
        chainhead[ColorNo]=now;
    }
    chaincolor[now]=ColorNo;
    int heavy=-1,maxi=0;
    for(auto u:graph[now]){
        if(u==ante){
            continue;
        }
        if(maxi<tam[u]){
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
        ColorNo++;
        hld(u,now);
    }
}
void dfs(int now,int ante){
    for(auto u:graph[now]){
        if(u==ante){
            continue;
        }
        padre[u]=now;
        altura[u]=altura[now]+1;
        dfs(u,now);
        tam[now]+=tam[u];
    }
}
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin >> n >> q;
    graph.resize(n);
    arr.assign(n,-1);
    padre.assign(n,-1);
    altura.assign(n,-1);
    tam.assign(n,1);
    pos.assign(n,-1);
    chaincolor.assign(n,-1);
    chainhead.assign(n,-1);
    tobeused.assign(n,-1);
    st.assign(4*n+5,-1);
    for(int i=0;i<n;i++){
        cin >> arr[i];
    }
    for(int i=1;i<n;i++){
        cin >> a >> b;
        graph[--a].push_back(--b);
        graph[b].push_back(a);
    }
    altura[0]=0;
    dfs(0,-1);
    hld(0,-1);
    build(0,0,n-1);
    while(q--){
        cin >> a >> b >> c;
        if(a==1){
            update(0,0,n-1,pos[--b],c);
        }else{
            cout << path(--b,--c) << ' ';
        }
    }
}