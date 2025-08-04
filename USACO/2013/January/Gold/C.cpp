#include <bits/stdc++.h>
using namespace std;
int N,q,tam,a,b,con;
int nums[500005],lazy[2000005];
int seg[2000005][4];
    void build(int node,int l,int r){
        if(l==r){
            seg[node][0]=1;
            seg[node][1]=l;
            seg[node][2]=l;
            seg[node][3]=l;
            return;
        }
        int mid=(l+r)>>1,hiji=2*node+1,hijd=2*node+2;
        build(hiji,l,mid);
        build(hijd,mid+1,r);
        if(seg[hiji][0]>=seg[hijd][0]){
            seg[node][0]=seg[hiji][0];
            seg[node][1]=seg[hiji][1];
        }else{
            seg[node][0]=seg[hijd][0];
            seg[node][1]=seg[hijd][1];
        }
        if(seg[hiji][2]!=-1 && seg[hijd][3]!=-1){
            if(seg[node][0]<seg[hijd][3]-seg[hiji][2]+1){
                seg[node][0]=seg[hijd][3]-seg[hiji][2]+1;
                seg[node][1]=seg[hiji][2];
            }else if(seg[node][0]==seg[hijd][3]-seg[hiji][2]+1){
                if(seg[hiji][2]<seg[node][1]){
                    seg[node][1]=seg[hiji][2];
                }
            }
        }
        if(seg[hijd][0]==r-(mid+1)+1 && seg[hiji][2]!=-1){
            seg[node][2]=seg[hiji][2];
        }else{
            seg[node][2]=seg[hijd][2];
        }
        if(seg[hiji][0]==mid-l+1 && seg[hijd][3]!=-1){
            seg[node][3]=seg[hijd][3];
        }else{
            seg[node][3]=seg[hiji][3];
        }
    }
    void propagate(int node,int l,int r,int val){
        if(val==-1){
            return;
        }
        if(val==1){
            seg[node][0]=0;
            seg[node][1]=-1;
            seg[node][2]=-1;
            seg[node][3]=-1;
        }else{
            seg[node][0]=r-l+1;
            seg[node][1]=l;
            seg[node][2]=l;
            seg[node][3]=r;
        }
        lazy[node]=val;
    }
    void push_down(int node,int l,int r){
        if(l==r){
            lazy[node]=-1;
            return;
        }
        int mid=(l+r)>>1,hiji=2*node+1,hijd=2*node+2;
        propagate(hiji,l,mid,lazy[node]);
        propagate(hijd,mid+1,r,lazy[node]);
        lazy[node]=-1;
    }
    void update(int node,int l,int r,int i,int j,int val){
        push_down(node,l,r);
        if(r<i || j<l){
            return;
        }else if(i<=l && r<=j){
            propagate(node,l,r,val);
            return;
        }
        int mid=(l+r)>>1,hiji=2*node+1,hijd=2*node+2;
        update(hiji,l,mid,i,j,val);
        update(hijd,mid+1,r,i,j,val);
        if(seg[hiji][0]>=seg[hijd][0]){
            seg[node][0]=seg[hiji][0];
            seg[node][1]=seg[hiji][1];
        }else{
            seg[node][0]=seg[hijd][0];
            seg[node][1]=seg[hijd][1];
        }
        if(seg[hiji][2]!=-1 && seg[hijd][3]!=-1){
            if(seg[node][0]<seg[hijd][3]-seg[hiji][2]+1){
                seg[node][0]=seg[hijd][3]-seg[hiji][2]+1;
                seg[node][1]=seg[hiji][2];
            }else if(seg[node][0]==seg[hijd][3]-seg[hiji][2]+1){
                if(seg[hiji][2]<seg[node][1]){
                    seg[node][1]=seg[hiji][2];
                }
            }
        }
        if(seg[hijd][0]==r-(mid+1)+1 && seg[hiji][2]!=-1){
            seg[node][2]=seg[hiji][2];
        }else{
            seg[node][2]=seg[hijd][2];
        }
        if(seg[hiji][0]==mid-l+1 && seg[hijd][3]!=-1){
            seg[node][3]=seg[hijd][3];
        }else{
            seg[node][3]=seg[hiji][3];
        }
        //cout << l << ' ' << r << ' ' << seg[node][0] << ' ' << seg[node][1] << ' ' << seg[node][2] << ' ' << seg[node][3] << '\n';
    }
    int query(int node,int l,int r,int val){
        push_down(node,l,r);
        if(l==r){
            return seg[node][1];
        }
        int mid=(l+r)>>1,hiji=2*node+1,hijd=2*node+2;
        if(seg[hiji][0]>=val){
            return query(hiji,l,mid,val);
        }else if(seg[hiji][2]!=-1 && seg[hijd][3]!=-1 && seg[hijd][3]-seg[hiji][2]+1>=val){
            return seg[hiji][2];
        }else{
            return query(hijd,mid+1,r,val);
        }
    }
    void segmenttree(int n){
        tam=n;
        for(int i=0;i<2000005;i++){
            lazy[i]=-1;
        }
        build(0,0,tam-1);
    }
char c;
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    freopen("seating.in","r",stdin);
    freopen("seating.out","w",stdout);
    cin >> N >> q;
    segmenttree(N);
    while(q--){
        cin >> c;
        if(c=='A'){
            cin >> b;
            //cout << "a";
            if(seg[0][0]<b){
                con++;
            }else{
                //cout << "b";
                int pos=query(0,0,N-1,b);
                //update todo del rango
                update(0,0,N-1,pos,pos+b-1,1);
                //cout << pos << endl;
            }
        }else{
            //cout << "c";
            cin >> a >> b;
            b--;a--;
            // update todo del rango;
            update(0,0,N-1,a,b,0);
        }
        /*for(int i=0;i<n;i++){
            cout << res.nums[i] << ' ';
        }
        cout << endl;*/
    }
    cout << con;
}