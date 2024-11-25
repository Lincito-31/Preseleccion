#include <bits/stdc++.h>
using namespace std;
int t;
int main(){
    scanf("%d",&t);
    while(t--){
        vector<pair<int,int>> puntos(3);
        scanf("%d%d%d%d%d%d",&puntos[0].first,&puntos[0].second,&puntos[1].first,&puntos[1].second,&puntos[2].first,&puntos[2].second);
        sort(puntos.begin(),puntos.end());
        //int lado1=(puntos[0].first-puntos[1].first)*(puntos[0].second-puntos[1].second)/2;
        //int lado2=(puntos[0].first-puntos[2].first)*(puntos[0].second-puntos[2].second)/2;
        //int lado3=(puntos[2].first-puntos[1].first)*(puntos[2].second-puntos[1].second)/2;
        int area=abs(puntos[1].first-puntos[0].first)*(puntos[0].second+puntos[1].second);
        area+=abs(puntos[2].first-puntos[1].first)*(puntos[1].second+puntos[2].second);
        area/=2;
        puntos[1].first-=puntos[0].first;
        puntos[2].first-=puntos[0].first;
        puntos[1].second-=puntos[0].second;
        puntos[2].second-=puntos[0].second;
        if(puntos[1].first*puntos[2].second-puntos[2].first*puntos[1].second>0){
            puntos[1].first+=puntos[0].first;
            puntos[2].first+=puntos[0].first;
            puntos[1].second+=puntos[0].second;
            puntos[2].second+=puntos[0].second;
            int lado1=abs(puntos[0].first-puntos[1].first)*abs(puntos[0].second-puntos[1].second)/2;
            int lado2=abs(puntos[0].first-puntos[2].first)*abs(puntos[0].second-puntos[2].second)/2;
            int lado3=abs(puntos[2].first-puntos[1].first)*abs(puntos[2].second-puntos[1].second)/2;
            area+=lado1+lado2+lado3;
        }
        printf("%d\n",area);
    }
}