#include <bits/stdc++.h>
using namespace std;
int n,q,a,b,c;
struct segmenttree{
    int N;
    vector<int> num;
    // pi-i,pi+i;
    vector<pair<int,int>> seg;
    void build(int node,int l,int r){
        if(l==r){
            seg[node]={num[l]-l,num[l]+l};
            return;
        }
        int mid=(l+r)>>1,hiji=2*node+1,hijd=2*node+2;
        build(hiji,l,mid);
        build(hijd,mid+1,r);
        seg[node].first=min(seg[hiji].first,seg[hijd].first);
        seg[node].second=min(seg[hiji].second,seg[hijd].second);
    }
    void update(int node,int l,int r,int pos,int val){
        if(l==r){
            seg[node]={val-l,val+l};
            return;
        }
        int mid=(l+r)>>1,hiji=2*node+1,hijd=2*node+2;
        if(pos<=mid){
            update(hiji,l,mid,pos,val);
        }else{
            update(hijd,mid+1,r,pos,val);
        }
        seg[node].first=min(seg[hiji].first,seg[hijd].first);
        seg[node].second=min(seg[hiji].second,seg[hijd].second);
    }
    int query(int node,int l,int r,int pos){
        if(l==r){
            return seg[node].first+l;
        }
        int mid=(l+r)>>1,hiji=2*node+1,hijd=2*node+2;
        int res=2e9;
        if(pos<=mid){
            return min(query(hiji,l,mid,pos),seg[hijd].second-pos);
        }else{
            return min(seg[hiji].first+pos,query(hijd,mid+1,r,pos));
        }
    }
    segmenttree(vector<int> x){
        N=x.size();
        num=x;
        seg.resize(4*N+5);
        build(0,0,N-1);
    }
};
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin >> n >> q;
    vector<int> nums(n);
    for(int i=0;i<n;i++){
        cin >> nums[i];
    }
    segmenttree res(nums);
    while(q--){
        cin >> a;
        if(a==1){
            cin >> b >> c;
            res.update(0,0,n-1,b-1,c);
        }else{
            cin >> b;
            cout << res.query(0,0,n-1,b-1) << '\n';
        }
    }
}