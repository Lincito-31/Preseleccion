#include <bits/stdc++.h>
using namespace std;
int n,q,a,b;
vector<int> nums,seg;
int dp[500000][3];
void build(int node,int l,int r){
    if(l==r){
        seg[node]=nums[l];
        return;
    }
    int hiji=2*node+1,hijd=2*node+2,mid=(l+r)/2;
    build(hiji,l,mid);
    build(hijd,mid+1,r);
    seg[node]=max(seg[hiji],seg[hijd]);
}
int query(int node,int l,int r,int i,int j){
    if(r<i || j<l){
        return 0;
    }
    if(i<=l && r<=j){
        return seg[node];
    }
    int hiji=2*node+1,hijd=2*node+2,mid=(l+r)/2;
    return max(query(hiji,l,mid,i,j),query(hijd,mid+1,r,i,j));
}
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin >> n;
    nums.resize(n);
    seg.resize(4*n+5);
    for(int i=0;i<n;i++){
        cin >> nums[i];
    }
    build(0,0,n-1);
    cin >> q;
    while(q--){
        int maxi=0;
        cin >> a >> b;
        a--;b--;
        for(int i=a;i<b;i++){
            for(int j=i+1;j<b;j++){
                maxi=max(maxi,nums[i]+nums[j]+query(0,0,n-1,2*j-i,b));
            }
        }
        cout << maxi << "\n";
    }
}