#include <bits/stdc++.h>
#define ALL(x) x.begin(),x.end()
#define REV(x) x.rbegin(),x.rend()
using namespace std;
typedef long long ll;
int n,con[200001],q,s,suma,maxi;
pair<int,int> par[200001];
int dsu[200001],tam[200001],now;
int find(int x){return dsu[x]==x?x:dsu[x]=find(dsu[x]);}
void unite(int x,int y){
    if((x=find(x))!=(y=find(y))){
        tam[y]+=tam[x];
        dsu[x]=y;
    }
}
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin >> n >> q;
    vector<int> nums(n);
    for(int i=0;i<n;i++){
        cin >> nums[i];
        con[nums[i]]++;
        if(par[nums[i]]==make_pair(0,0)){
            par[nums[i]]={i+1,i+1};
        }else{
            par[nums[i]].second=i+1;
        }
    }
    vector<pair<int,int>> ord;
    for(int i=1;i<=200000;i++){
        dsu[i]=i;
        tam[i]=1;
        if(par[i]!=make_pair(0,0)){
            ord.push_back(par[i]);
        }
    }
    sort(ALL(ord));
    for(int i=0;i<ord.size();i++){
        now=max(now,ord[i].first+1);
        for(;now<=ord[i].second;now++){
            unite(now,now-1);
        }
    }
    now=0;
    for(int i=0;i<n;i++){
        if((s=find(i+1))!=now){
            suma+=tam[now]-maxi;
            maxi=con[nums[i]];
            now=s;
        }else{
            maxi=max(maxi,con[nums[i]]);
        }
        //cout << find(i+1) << ' ';
    }
    suma+=tam[s]-maxi;
    cout << suma;
}