#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int t,n,l,r,maxi,maxd;
vector<int> nums;
bool xd;
struct Segment{
    vector<int> arbol,val;
    int N;
    void build(int node,int l,int r){
        if(l==r){
            arbol[node]=val[l];
            return;
        }
        int mid=(l+r)>>1,hiji=2*node+1,hijd=2*node+2;
        build(hiji,l,mid);
        build(hijd,mid+1,r);
        arbol[node]=min(arbol[hiji],arbol[hijd]);
    }
    int query(int node,int l,int r,int i,int j){
        if(j<i){
            return 1e9;
        }
        if(r<i || j<l){
            return 1e9;
        }else if(i<=l && r<=j){
            return arbol[node];
        }
        int mid=(l+r)>>1,hiji=2*node+1,hijd=2*node+2;
        return min(query(hiji,l,mid,i,j),query(hijd,mid+1,r,i,j));
    }
    Segment(vector<int> a){
        arbol.resize(4*(N=a.size())+5);
        val=a;
        build(0,0,N-1);
    }
};
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin >> t;
    while(t--){
        xd=false;
        cin >> n;
        nums.resize(n);
        for(int i=0;i<n;i++){
            cin >> nums[i];
        }
        Segment st(nums);
        maxd=0;
        vector<int> pref(n);
        pref[0]=nums[0];
        for(int i=1;i<n;i++){
            pref[i]=max(pref[i-1],nums[i]);
        }
        for(int i=n-1;i>=2 && !xd;i--){
            maxd=max(maxd,nums[i]);
            int x=upper_bound(pref.begin(),pref.end(),maxd)-pref.begin();
            x--;
            x=min(x,i-2);
            if(pref[x]==maxd){
                if(st.query(0,0,n-1,x+1,i-1)==maxd){
                    l=x;r=i;
                    xd=true;
                }
                if(x>0){
                    if(pref[x-1]==maxd){
                        if(st.query(0,0,n-1,x,i-1)==maxd){
                            l=x-1;r=i;
                            xd=true;
                        }
                    }
                }
            }
        }
        if(xd){
            cout << "YES\n" << l+1 << ' ' << r-l-1 << ' ' << n-r << '\n';
        }else{
            cout << "NO\n";
        }
    }
}