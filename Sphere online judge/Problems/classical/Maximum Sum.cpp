#include <bits/stdc++.h>
using namespace std;
typedef pair<int,int> pii;
int n,a,b,q;
char t;
vector<pii> segt;
vector<int> nums;
void init(int node,int l, int r){
    if(l==r){
        segt[node]={nums[l],0};
        return;
    }
    int hiji=2*node+1,hijd=2*node+2;
    int mid=(l+r)>>1;
    init(hiji,l,mid);
    init(hijd,mid+1,r);
    segt[node]={max(segt[hiji].first,segt[hijd].first),max(max(segt[hiji].second,segt[hijd].second),min(segt[hiji].first,segt[hijd].first))};
}
pii query(int node,int l,int r,int i,int j){
    if(i<=l && r<=j){
        return segt[node];
    }
    if(r<i || j<l){
        return {0,0};
    }
    int hiji=2*node+1,hijd=2*node+2;
    int mid=(l+r)>>1;
    pii iz=query(hiji,l,mid,i,j);
    pii de=query(hijd,mid+1,r,i,j);
    return {max(iz.first,de.first),max(max(iz.second,de.second),min(iz.first,de.first))};
}
void update(int node,int l,int r,int pos,int val){
    if(l==r){
        segt[node]={val,0};
        return;
    }
    int mid=(l+r)>>1;
    int hiji=2*node+1,hijd=2*node+2;
    if(pos<=mid){
        update(hiji,l,mid,pos,val);
    }else{
        update(hijd,mid+1,r,pos,val);
    }
    segt[node]={max(segt[hiji].first,segt[hijd].first),max(max(segt[hiji].second,segt[hijd].second),min(segt[hiji].first,segt[hijd].first))};
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);cout.tie(NULL);
    cin >> n;
    nums.resize(n);
    segt.resize(3*n+5);
    for(int i=0;i<n;i++){
        cin >> nums[i];
    }
    init(0,0,n-1);
    cin >> q;
    while(q--){
        cin >> t >> a >> b;
        if(t=='Q'){
            pii res=query(0,0,n-1,a-1,b-1);
            cout << res.first+res.second << "\n";
        }else{
            update(0,0,n-1,a-1,b);
        }
    }
}