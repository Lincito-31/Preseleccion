#include <bits/stdc++.h>
using namespace std;
typedef vector<int> vi;
vector<vi> pos(1e7+1);
vi dju,tam;
vector<bool> visitednums,visited3162(1e7+1,false);
int n,q,x,y;
int find(int a){
    if(dju[a]==a){
        return a;
    }
    return dju[a]=find(dju[a]);
}
void unite(int a,int b){
    a=find(a);
    b=find(b);
    if(a==b){
        return;
    }
    if(tam[a]>tam[b]){
        dju[b]=a;
    }else{
        dju[a]=b;
    }
}
int main(){
    scanf("%d",&n);
    visitednums.assign(n,false);
    bool find1=false;
    vi nums(n);
    dju.resize(n);
    tam.assign(n,1);
    vector<vi> div(n);
    for(int i=0;i<n;i++){
        dju[i]=i;
        scanf("%d",&nums[i]);
        if(nums[i]==1){
            find1=true;
        }
        int aux=nums[i];
        for(int j=2;j<3162 && aux>1;j++){
            if(aux%j==0){
                div[i].push_back(j);
                pos[j].push_back(i);
                while(aux%j==0){
                    aux/=j;
                }
            }
        }
        if(aux>1){
            pos[aux].push_back(i);
            div[i].push_back(aux);
        }
    }
    for(int i=0;i<n;i++){
        if(visitednums[i]){
            continue;
        }
        visitednums[i]=true;
        queue<int> auxi;
        for(auto u:div[i]){
            auxi.push(u);
        }
        while(!auxi.empty()){
            int u=auxi.front();
            auxi.pop();
            if(visited3162[u]){
                continue;
            }
            visited3162[u]=true;
            for(auto k:pos[u]){
                unite(i,k);
                if(visitednums[k]){
                    continue;
                }
                visitednums[i]=true;
                for(auto p:div[k]){
                    auxi.push(p);
                }
            }
        }
    }
    scanf("%d",&q);
    while(q--){
        scanf("%d%d",&x,&y);
        if(find1){
            printf("SI\n");
            continue;
        }
        if(nums[x]==nums[y]){
            printf("SI\n");
        }else{
            if(find(x)==find(y)){
                printf("SI\n");
            }else{
                printf("NO\n");
            }
        }
    }
}