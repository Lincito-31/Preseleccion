#include <bits/stdc++.h>
using namespace std;
typedef vector<int> vi;
string s;
int n,now=1;
vi sum(4e6),mini(4e6),maxi(4e6);

void update(int node,int l,int r,int p,int v){
    if(l==r){
        sum[node]=v;
        maxi[node]=v;
        mini[node]=v;
        return ;
    }
    int mid=(l+r)/2;
    int left_node=2*node+1;
    int right_node=2*node+2;
    if(p<=mid){
        update(left_node,l,mid,p,v);
    }
    else{
        update(right_node,mid+1,r,p,v);
    }
    sum[node]=sum[left_node]+sum[right_node];
    maxi[node]=max(maxi[left_node],sum[left_node]+maxi[right_node]);
    mini[node]=min(mini[left_node],sum[left_node]+mini[right_node]);
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin>>n>>s;
    for(int i=0;i<n;i++){
        if(s[i]=='L'){
            if(now>1){
                now--;
            }
        }else if(s[i]=='R'){
            now++;
        }else if(s[i]=='('){
            update(1,1,n,now,1);
        }else if(s[i]==')'){
            update(1,1,n,now,-1);
        }else{
            update(1,1,n,now,0);
        }

        if(mini[1]>=0 && sum[1]==0){
            cout << maxi[1] << " ";
        }else{
            cout << "-1 ";
        }
    }
}