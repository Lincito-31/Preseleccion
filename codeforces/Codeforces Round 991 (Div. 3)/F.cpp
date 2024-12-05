#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#define ALL(x) x.begin(),x.end()
#define REV(x) x.rbegin(),x.rend()
#define MOD 1000000007
using namespace __gnu_pbds;
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef vector<long long> vll;
typedef pair<int,int> pii;
typedef pair<long long,long long> pll;
typedef tree<int,null_type,less<int>,rb_tree_tag,tree_order_statistics_node_update> indexed_set;
int t,n,q,x,y;
vi dif;
vi segtree;
int gcd(int a,int b){
    if(a<b){
        swap(a,b);
    }
    if(b==0){
        return a;
    }
    return gcd(b,a%b);
}
void built(int node,int l,int r){
    if(l==r){
        segtree[node]=dif[l];
        return;
    }
    int hiji=2*node+1,hijd=2*node+2;
    int mid=(l+r)/2;
    built(hiji,l,mid);
    built(hijd,mid+1,r);
    segtree[node]=gcd(segtree[hiji],segtree[hijd]);
}
int query(int node,int i,int j,int l,int r){
    if(l>j || r<i){
        return 0;
    }
    if(i<=l && r<=j){
        return segtree[node];
    }
    int hiji=2*node+1,hijd=2*node+2;
    int mid=(l+r)/2;
    int ff=query(hiji,i,j,l,mid);
    int ss=query(hijd,i,j,mid+1,r);
    return gcd(ff,ss);
}
int main(){
    scanf("%d",&t);
    while(t--){
        scanf("%d%d",&n,&q);
        vi nums(n);
        dif.resize(n);
        segtree.resize(4*n+5);
        for(int i=0;i<n;i++){
            scanf("%d",&nums[i]);
        }
        dif[0]=0;
        for(int i=1;i<n;i++){
            dif[i]=abs(nums[i]-nums[i-1]);
        }
        built(0,0,n-1);
        while(q--){
            scanf("%d%d",&x,&y);
            x--;y--;
            if(x==y){
                printf("0 ");
            }else{
                printf("%d ",query(0,x+1,y,0,n-1));
            }
        }
        printf("\n");
    }
}