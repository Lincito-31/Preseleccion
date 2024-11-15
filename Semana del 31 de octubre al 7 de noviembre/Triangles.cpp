#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<ll> vll;
typedef vector<int> vi;
int n,q,t,a,b;
vi nums;
vector<vi> st;
// Que grande Mati
void build(int pos,int l,int r){
    if(l==r){
        st[pos][0]=nums[l];
    }else{
        int mid=(l+r)>>1;
        int hiji=(pos<<1)+1,hijd=(pos<<1)+2;
        build(hiji,l,mid);
        build(hijd,mid+1,r);
        int iz=0,de=0,con=1;
        while(iz<st[hiji].size() && de<st[hijd].size() && con<=44){
            if(st[hiji][iz]>=st[hijd][de]){
                st[pos][con-1]=st[hiji][iz];
                iz++;
            }else{
                st[pos][con-1]=st[hijd][de];
                de++;
            }
            con++;
        }
        while(iz<st[hiji].size() && con<=44){
            st[pos][con-1]=st[hiji][iz];
            iz++;
            con++;
        }
        while(de<st[hijd].size() && con<=44){
            st[pos][con-1]=st[hijd][de];
            de++;
            con++;
        }
    }
}
vi query(int pos,int i,int j,int l,int r){
    if(r<i || j<l){
        vi res;
        return res;
    }
    if(i<=l && r<=j){
        return st[pos];
    }
    vi res(44,0);
    int mid=(l+r)>>1;
    int hiji=(pos<<1)+1,hijd=(pos<<1)+2;
    vi izqui=query(hiji,i,j,l,mid);
    vi derec=query(hijd,i,j,mid+1,r);
    int iz=0,de=0,con=1;
    while(iz<izqui.size() && de<derec.size() && con<=44){
        if(izqui[iz]>=derec[de]){
            res[con-1]=izqui[iz];
            iz++;
        }else{
            res[con-1]=derec[de];
            de++;
        }
        con++;
    }
    while(iz<izqui.size() && con<=44){
        res[con-1]=izqui[iz];
        iz++;
        con++;
    }
    while(de<derec.size() && con<=44){
        res[con-1]=derec[de];
        de++;
        con++;
    }
    return res;
}
void update(int pos,int l,int r,int index,int val){
    if(l==r && l==index){
        st[pos][0]=val;
        return;
    }else if(l<=index && index<=r){
        int mid=(l+r)>>1;
        int hiji=(pos<<1)+1,hijd=(pos<<1)+2;
        update(hiji,l,mid,index,val);
        update(hijd,mid+1,r,index,val);
        //st[pos].clear();
        int iz=0,de=0,con=1;
        while(iz<st[hiji].size() && de<st[hijd].size() && con<=44){
            if(st[hiji][iz]>=st[hijd][de]){
                st[pos][con-1]=st[hiji][iz];
                iz++;
            }else{
                st[pos][con-1]=st[hijd][de];
                de++;
            }
            con++;
        }
        while(iz<st[hiji].size() && con<=44){
            st[pos][con-1]=st[hiji][iz];
            iz++;
            con++;
        }
        while(de<st[hijd].size() && con<=44){
            st[pos][con-1]=st[hijd][de];
            de++;
            con++;
        }
    }
}
int main(){
    scanf("%d%d",&n,&q);
    nums.resize(n);
    st.assign(4*n+5,vi(44,0));
    for(int i=0;i<n;i++){
        scanf("%d",&nums[i]);
    }
    build(0,0,n-1);
    while(q--){
        scanf("%d%d%d",&t,&a,&b);
        if(t){
            bool xd=false;
            vi res=query(0,a,b,0,n-1);
            if(res.size()<3){
                // nada
            }else{
                int now=0;
                while(now<=res.size()-3){
                    if(res[now]<res[now+1]+res[now+2]){
                        printf("%d\n",res[now]+res[now+1]+res[now+2]);
                        xd=true;
                        break;
                    }
                    now++;
                }
                if(xd){
                    continue;
                }
            }
            printf("0\n");
        }else{
            update(0,0,n-1,a,b);
        }
    }
}