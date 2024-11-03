#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<int> vi;
int n,q,t,a,b;
vector<map<int,int>> tree;
vi nums;
void init(int now,int l,int r){
    if(l==r){
        tree[now][nums[l]]++;
    }else{
        int mid=(l+r)/2;
        int hiji=2*now+1,hijd=2*now+2;
        init(hiji,l,mid);
        init(hijd,mid+1,r);
        for(auto u:tree[hiji]){
            tree[now][u.first]+=u.second;
        }
        for(auto u:tree[hijd]){
            tree[now][u.first]+=u.second;
        }
    }
}
void update(int pos,int val,int now,int l,int r,int ante){
    if(l==r && l==pos){
        tree[now][ante]--;
        if(tree[now][ante]==0){
            tree[now].erase(ante);
        }
        tree[now][val]++;
    }else if(l<=pos && pos<=r){
        tree[now][ante]--;
        if(tree[now][ante]==0){
            tree[now].erase(ante);
        }
        tree[now][val]++;
        int mid=(l+r)/2;
        int hiji=2*now+1,hijd=2*now+2;
        update(pos,val,hiji,l,mid,ante);
        update(pos,val,hijd,mid+1,r,ante);
    }
}
map<int,int> query(int iz,int de,int now,int l,int r){
    map<int,int> res;
    if(de<l || r<iz){
        return res;
    }
    if(iz<=l && r<=de){
        return tree[now];
    }
    int mid=(l+r)/2;
    int hiji=2*now+1,hijd=2*now+2;
    map<int,int> izqui=query(iz,de,hiji,l,mid);
    map<int,int> derec=query(iz,de,hijd,mid+1,r);
    for(auto u:izqui){
        res[u.first]+=u.second;
    }
    for(auto u:derec){
        res[u.first]+=u.second;
    }
    return res;
}
int checkear(map<int,int> prueb){
    int res=0;
    auto p=prueb.end();
    p--;
    int penu=-1,antepenu=-1,last=p->first;
    if(p->second>=3){
        penu=last;
        antepenu=last;
    }else if(p->second==2){
        penu=last;
        if(p!=prueb.begin()){
            p--;
            antepenu=p->first;
        }
    }else if(p!=prueb.begin()){
        p--;
        penu=p->first;
        if(p->second>=2){
            antepenu=penu;
        }else{
            if(p!=prueb.begin()){
                p--;
                antepenu=p->first;
            }
        }
    }
    if(antepenu==-1){
        return 0;
    }
    if(antepenu+penu>last){
        return antepenu+penu+last;
    }
    while(p!=prueb.begin()){
        if(antepenu+penu>last){
            return antepenu+penu+last;
        }
        last=penu;
        penu=antepenu;
        if(p->second>=2){
            if(penu+antepenu>last){
                return antepenu+penu+last;
            }
        }
        if(p->second>=3){
            return 3*antepenu;
        }else{
            p--;
            penu=p->first;
            if(penu+antepenu>last){
                return antepenu+penu+last;
            }
        }
    }
    return 0;
}
int main(){
    scanf("%d%d",&n,&q);
    nums.resize(n);
    for(int i=0;i<n;i++){
        scanf("%d",&nums[i]);
    }
    tree.resize(5*n);
    init(0,0,n-1);
    while(q--){
        scanf("%d%d%d",&t,&a,&b);
        if(t){
            //query
            map<int,int> prueb=query(a,b,0,0,n-1);
            printf("%d\n",checkear(prueb));
        }else{
            //update
            int x=nums[a];
            nums[a]=b;
            update(a,b,0,0,n-1,x);
        }
    }
}