#include <bits/stdc++.h>
using namespace std;
int n,k,maxi=0,now=1;
vector<pair<int,int>> posi(101,{0,0});
vector<int> conjunto;
vector<int> respuesta;
void calc(){
    posi[0]={1,0};
    for(int kk=0;kk<100;kk++){
        for(int i=0;i<k;i++){
            for(int j=100;j>=0;j--){
                if(posi[j].first==1){
                    if(posi[j].second<n){
                        if(j+conjunto[i]>100){
                            continue;
                        }
                        if(posi[j+conjunto[i]].first==0){
                            posi[j+conjunto[i]]=posi[j];
                            posi[j+conjunto[i]].second++;
                        }else if(posi[j+conjunto[i]].second>posi[j].second+1){
                            posi[j+conjunto[i]].second=posi[j].second+1;
                        }
                    }
                }
            }
        }
    }
    while(posi[now].first==1){
        now++;
    }
}
void solve(int pos,int num){
    if(pos==k){
        now=1;
        calc();
        if(maxi<now-1){
            maxi=now-1;
            respuesta=conjunto;
        }
        posi.assign(101,{0,0});
        return;
    }
    if(num>100){
        return;
    }
    conjunto[pos]=num;
    solve(pos+1,num+1);
    conjunto[pos]=0;
    solve(pos,num+1);
}
int main(){
    while(true){
        scanf("%d%d",&n,&k);
        if(n==0 && k==0){
            break;
        }
        if(n==0 || k==0){
            printf("0 0 -> 0\n");
            continue;
        }
        maxi=0;
        conjunto.assign(k,0);
        conjunto[0]=1;
        solve(1,2);
        for(int i=0;i<k;i++){
            printf("%d ",respuesta[i]);
        }
        printf("-> %d\n",maxi);
    }
}