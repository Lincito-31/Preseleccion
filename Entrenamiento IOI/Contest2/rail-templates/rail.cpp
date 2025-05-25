#include "rail.h"
#include <bits/stdc++.h>
#define ALL(x) x.begin(),x.end()
using namespace std;
vector<vector<int>> aske;
int ask(int x,int y){
    if(y>x){
        swap(x,y);
    }
    if(aske[x][y]==0){
        aske[x][y]=getDistance(x,y);
    }
    return aske[x][y];
}
void findLocation(int N, int first, int location[], int stype[])
{
    aske.assign(N,vector<int>(N,0));
    stype[0]=1;
    location[0]=first;
    int posicionde=1e9+7,posicioniz=1e9+7,posde,posiz;
    for(int i=1;i<N;i++){
        int x=ask(0,i);
        if(x<posicionde){
            posicionde=x;
            posde=i;
        }
    }
    posicionde+=first;
    stype[posde]=2;
    location[posde]=posicionde;
    for(int i=0;i<N;i++){
        if(i==posde){
            continue;
        }
        int x=ask(posde,i);
        if(x<posicioniz){
            posicioniz=x;
            posiz=i;
        }
    }
    posicioniz=posicionde-posicioniz;
    stype[posiz]=1;
    location[posiz]=posicioniz;
    vector<int> direccion(N);
    int coniz=0,conde=0;
    direccion[posiz]=direccion[posde]=-1;
    vector<pair<int,int>> distde,distiz;
    for(int i=0;i<N;i++){
        if(i==posiz || i==posde){
            continue;
        }
        int x=ask(posiz,i),y=ask(posde,i);
        if(x<y){
            direccion[i]=1;
            conde++;
            distde.push_back({x,i});
        }else{
            direccion[i]=0;
            coniz++;
            distiz.push_back({y,i});
        }
    }
    sort(ALL(distde));
    sort(ALL(distiz));
    for(int i=0;i<distde.size();i++){
        stype[distde[i].second]=2;
        location[distde[i].second]=location[posiz]+ask(posiz,distde[i].second);
        if(i+1<distde.size()){
            
        }
    }
    /*if(coniz==1){
        for(int i=0;i<N;i++){
            if(direccion[i]==0){
                stype[i]=1;
                location[i]=location[posde]-ask(i,posde);
            }
        }
    }
    if(conde==1){
        for(int i=0;i<N;i++){
            if(direccion[i]==1){
                stype[i]=2;
                location[i]=location[posiz]+ask(i,posiz);
            }
        }
    }else if(coniz>=2){

    }*/
    return;
}
