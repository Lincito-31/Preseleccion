#include "rail.h"
#include <bits/stdc++.h>
#define ALL(x) x.begin(),x.end()
#define REV(x) x.rbegin(),x.rend()
using namespace std;
int distan[5000][5000];
int ask(int x,int y){
    if(x>y){
        swap(x,y);
    }
    if(distan[x][y]==0){
        distan[x][y]=getDistance(x,y);
    }
    return distan[x][y];
}
void findLocation(int N, int first, int location[], int stype[])
{
    stype[0]=1;
    location[0]=first;
    vector<pair<int,int>> dist(N-1);
    for(int i=1;i<N;i++){
        dist[i-1]={ask(0,i),i};
    }
    sort(ALL(dist));
    set<int> izquierda,derecha;
    int izq=0,der=dist[1].second;
    izquierda.insert(location[izq]);
    derecha.insert(location[der]);
    location[der]=first+dist[1].first;
    stype[der]=2;
    for(int i=2;i<N;i++){
        int x=ask(izq,dist[i].second),y=ask(der,dist[i].second);
        //op1 esta directo con izq
        auto p=izquierda.lower_bound(location[izq]+x);
        p--;
        if(location[der]-*p+location[izq]+x-*p==y){
            stype[dist[i].second]=2;
            location[dist[i].second]=location[izq]+x;
            derecha.insert(location[dist[i].second]);
            if(location[dist[i].second]>location[der]){
                der=dist[i].second;
            }
        }else{
            stype[dist[i].second]=1;
            location[dist[i].second]=location[der]-y;
            izquierda.insert(location[dist[i].second]);
            if(location[dist[i].second]<location[izq]){
                izq=dist[i].second;
            }
        }
    }
    return;
}
