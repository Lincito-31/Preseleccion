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
    int res=-1;
    int nue=-1;
    auto p=prueb.end();
    p--;
    int last=p->first,penu=-1,antepenu=-1;
    if(p->second>=3){
        nue=3*p->first;
    }
    if(p->second==2 && p!=prueb.begin()){
        auto q=p;
        q--;
        nue=2*p->first+q->first;
    }
    if(p!=prueb.begin()){
        p--;
        penu=p->first;
    }
    if(p->second>=3){
        nue=max(nue,3*p->first);
    }
    if(p->second==2 && p!=prueb.begin()){
        auto q=p;
        q--;
        nue=max(nue,2*p->first+q->first);
    }
    if(p!=prueb.begin()){
        p--;
        antepenu=p->first;
    }
    if(p->second>=3){
        nue=max(nue,3*p->first);
    }
    if(p->second==2 && p!=prueb.begin()){
        auto q=p;
        q--;
        nue=max(nue,2*p->first+q->first);
    }
    if(antepenu+penu>last){
        res=antepenu+penu+last;
    }
    res=max(res,nue);
    if(res==-1){
        while(p!=prueb.begin()){
            p--;
            last=penu;
            penu=antepenu;
            antepenu=p->first;
            if(p->second>=2){
                auto q=p;
                q++;
                if(2*p->first>q->first){
                    nue=2*p->first+q->first;
                }
            }
            if(p->second>=3){
                nue=3*p->first;
            }
            if(p->second==2 && p!=prueb.begin()){
                auto q=p;
                q--;
                nue=2*p->first+q->first;
            }
            if(antepenu+penu>last){
                res=antepenu+penu+last;
            }
            res=max(res,nue);
            if(res!=-1){
                break;
            }
        }
    }
    return res==-1?0:res;
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
            bool xdd=false;
            map<int,int> prueb=query(a,b,0,0,n-1);
            int res=-1;
            int nue=-1;
            auto p=prueb.end();
            p--;
            int last=p->first,penu=-1,antepenu=-1;
            if(p->second>=3){
                nue=3*p->first;
            }
            if(p->second==2 && p!=prueb.begin()){
                auto q=p;
                q--;
                nue=2*p->first+q->first;
            }
            if(p!=prueb.begin()){
                p--;
                penu=p->first;
            }
            if(p->second>=3){
                nue=max(nue,3*p->first);
            }
            if(p->second==2 && p!=prueb.begin()){
                auto q=p;
                q--;
                nue=max(nue,2*p->first+q->first);
            }
            if(p!=prueb.begin()){
                p--;
                antepenu=p->first;
            }
            if(p->second>=3){
                nue=max(nue,3*p->first);
            }
            if(p->second==2 && p!=prueb.begin()){
                auto q=p;
                q--;
                nue=max(nue,2*p->first+q->first);
            }
            if(antepenu+penu>last){
                res=antepenu+penu+last;
            }
            res=max(res,nue);
            if(res==-1){
                while(p!=prueb.begin()){
                    p--;
                    last=penu;
                    penu=antepenu;
                    antepenu=p->first;
                    if(p->second>=2){
                        auto q=p;
                        q++;
                        if(2*p->first>q->first){
                            nue=2*p->first+q->first;
                        }
                    }
                    if(p->second>=3){
                        nue=3*p->first;
                    }
                    if(p->second==2 && p!=prueb.begin()){
                        auto q=p;
                        q--;
                        nue=2*p->first+q->first;
                    }
                    if(antepenu+penu>last){
                        res=antepenu+penu+last;
                    }
                    res=max(res,nue);
                    if(res!=-1){
                        break;
                    }
                }
            }
            if(res==-1){
                res=0;
            }
            printf("%d\n",res);
        }else{
            //update
            int x=nums[a];
            nums[a]=b;
            update(a,b,0,0,n-1,x);
        }
    }
}