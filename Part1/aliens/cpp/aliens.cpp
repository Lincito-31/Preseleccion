#include "aliens.h"
#include <bits/stdc++.h>
#define ALL(x) x.begin(),x.end()
typedef long long ll;
using namespace std;
vector<pair<ll,ll>> puntos;
ll dp[4005][4005],res=1e18,N;
// minima cantidad de cuadrantes que tomo hasta la pos i con k fotos
bool cmp(pair<ll,ll> x,pair<ll,ll> y){
    if(x.first==y.first){
        return x.second>y.second;
    }
    return x.first<y.first;
}
ll cuadrado(ll x){
    return x*x;
}
pair<ll,ll> solve(ll constante){
    pair<ll,ll> minidp[N+5];
    // minidp[i]: first:la minimacantidad de cuadrantes hasta pos i,second=la cantidad de fotos;
    //por cada nuevo foto quito constante
    for(int i=0;i<N+5;i++){
        minidp[i]={1e18,1e18};
    }
    minidp[0]={0,0};
    for(int i=1;i<=N;i++){
        //unir con anteriores
        for(int j=1;j<=i;j++){
            ll cant_cua=cuadrado(puntos[i].second-puntos[j].first+1);
            // verificar si une con lo anterior;
            ll limiteiz=puntos[j].first;
            ll limitede=puntos[j-1].second;
            if(limiteiz<=limitede){
                cant_cua-=cuadrado(limitede-limiteiz+1);
            }
            if(minidp[j-1].first+cant_cua+constante<minidp[i].first){
                minidp[i].first=minidp[j-1].first+cant_cua+constante;
                minidp[i].second=minidp[j-1].second+1;
            }
        }
    }
    return minidp[N];
}
ll take_photos(int n,int m,int k,vector<int> r,vector<int> c){
    puntos.resize(n);
    for(ll i=0;i<n;i++){
        if(r[i]>c[i]){
            swap(r[i],c[i]);
        }
        puntos[i]={r[i],c[i]};
    }
    sort(ALL(puntos),cmp);
    vector<pair<ll,ll>> temp;
    temp.push_back({-2e9,-2e9});
    temp.push_back(puntos[0]);
    for(ll i=1;i<n;i++){
        if(puntos[i].second<=temp.back().second){
            continue;
        }
        temp.push_back(puntos[i]);
    }
    puntos=temp;
    n=puntos.size()-1;
    N=n;
    ll iz=0,de=1e18;
    while(iz<de){
        ll mid=(iz+de)>>1;
        // mientras mas grande sea mid, k sera mas pequeño
        if(solve(mid).second<=k){
            de=mid;
        }else{
            iz=mid+1;
        }
    }
    pair<ll,ll> sol=solve(iz);
    return sol.first-sol.second*iz;
    for(ll i=0;i<=n;i++){
        for(ll j=0;j<=k;j++){
            dp[i][j]=1e18;
        }
    }
    dp[0][0]=0;
    for(ll i=1;i<=n;i++){
        for(ll j=1;j<=k;j++){
            // unir con los pasados;
            for(ll l=1;l<=i;l++){
                // unir del l al i
                ll cant_cua=cuadrado(puntos[i].second-puntos[l].first+1);
                // verificar si une con lo anterior;
                ll limiteiz=puntos[l].first;
                ll limitede=puntos[l-1].second;
                if(limiteiz<=limitede){
                    cant_cua-=cuadrado(limitede-limiteiz+1);
                }
                dp[i][j]=min(dp[i][j],dp[l-1][j-1]+cant_cua);
            }
        }
    }
    for(int i=0;i<=k;i++){
        res=min(res,dp[n][i]);
    }
    return res;
}