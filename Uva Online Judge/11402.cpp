#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef vector<long long> vll;
typedef pair<long long,long long> pll;
typedef tree<int,null_type,less<int>,rb_tree_tag,tree_order_statistics_node_update> intset;
int T,t,N,Q,x,y;
string st,a;
char ca;
struct SEGMENTTREE{
    vector<int> lazy;
    int hiji(int i){return ((i<<1)+1);}
    int hijd(int i){return ((i<<1)+2);}
    vector<int> treee;
    void builddd(int node,int l,int r){
        if(l==r){
            if(st[l]=='1'){
                treee[node]=1;
            }else{
                treee[node]=0;
            }
            return;
        }
        int hi=hiji(node),hd=hijd(node);
        int mid=(l+r)>>1;
        builddd(hi,l,mid);
        builddd(hd,mid+1,r);
        treee[node]=treee[hi]+treee[hd];
    }
    void build(){
        lazy.assign(4*N+5,0);
        treee.assign(4*N+5,0);
        builddd(0,0,N-1);
    }
    void propagate(int node,int l,int r){
        if(l==r){
            if(lazy[node]==1){
                treee[node]=1;
            }else if(lazy[node]==2){
                treee[node]=0;
            }else if(lazy[node]==3){
                treee[node]=1-treee[node];
            }
            lazy[node]=0;
            return;
        }
        int hi=hiji(node),hd=hijd(node);
        int mid=(l+r)>>1;
        if(lazy[node]!=0){
            propagate(hi,l,mid);
            propagate(hd,mid+1,r);
            lazy[hi]=lazy[hd]=lazy[node];
            if(lazy[node]==1){
                treee[node]=r-l+1;
            }else if(lazy[node]==2){
                treee[node]=0;
            }else{
                treee[node]=r-l+1-treee[node];
            }
            lazy[node]=0;
        }
    }
    void update(int node,int l,int r,int i,int j){
        propagate(node,l,r);
        if(r<i || j<l){
            return;
        }
        int hi=hiji(node),hd=hijd(node);
        int mid=(l+r)>>1;
        if(ca=='F'){
            if(i<=l && r<=j){
                lazy[node]=1;
                propagate(node,l,r);
                return;
            }
        }else if(ca=='E'){
            if(i<=l && r<=j){
                lazy[node]=2;
                propagate(node,l,r);
                return;
            }
        }else{
            if(i<=l && r<=j){
                lazy[node]=3;
                propagate(node,l,r);
                return;
            }
        }
        update(hi,l,mid,i,j);
        update(hd,mid+1,r,i,j);
        treee[node]=treee[hi]+treee[hd];
    }
    int query(int node,int l,int r,int i,int j){
        propagate(node,l,r);
        if(r<i || j<l){
            return 0;
        }
        if(i<=l && r<=j){
            return treee[node];
        }
        int mid=(l+r)>>1;
        return (query(hiji(node),l,mid,i,j)+query(hijd(node),mid+1,r,i,j));
    }
};

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin >> T;
    for(int i=1;i<=T;i++){
        int j=1;
        cin >> N;
        st="";
        while(N--){
            cin >> t >> a;
            while(t--){
                st+=a;
            }
        }
        N=st.size();
        cout << st << endl;
        SEGMENTTREE STT;
        STT.build();
        cout << "Case " << i << ":\n"; 
        cin >> Q;
        while(Q--){
            cin >> ca >> x >> y;
            /*if(ca=='S'){
                cout << 'Q' << j << ": " << STT.query(0,0,N-1,x,y) << '\n';
                j++;
            }else{
                STT.update(0,0,N-1,x,y);
            }*/
        }
    }
}