#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<ll> vll;
typedef vector<int> vi;
vector<vi> gra;
vector<vll> val;
vi person;
ll tot=0;
ll paso1(int a,int b){
    ll sum=0;
    for(auto u:gra[a]){
        if(u==b){
            continue;
        }
        val[a].push_back(paso1(u,a));
        sum+=val[a].back();
    }
    sum+=person[a];
    return sum;
}
void paso2(int a,int b){
    int con=0;
    for(auto u:gra[a]){
        if(u==b){
            continue;
        }
        val[u].push_back(tot-val[a][con]);
        paso2(u,a);
        con++;
    }
}
int LocateCentre(int N, int pp[], int S[], int D[]) {
    gra.resize(N);
    person.resize(N);
    val.resize(N);
    for(int i=0;i<N-1;i++){
        gra[S[i]].push_back(D[i]);
        gra[D[i]].push_back(S[i]);
        person[i]=pp[i];
        tot+=person[i];
    }
    person[N-1]=pp[N-1];
    tot+=person[N-1];
    paso1(0,-1);
    paso2(0,-1);
    ll mini=1e18;
    int node=0;
    for(int i=0;i<N;i++){
        ll maxi=0;
        for(auto u:val[i]){
            maxi=max(maxi,u);
        }
        if(maxi<mini){
            mini=maxi;
            node=i;
        }
    }
   return node;
}
static int N,P[1000000],S[1000000],D[1000000];
int main(){
    int i;
    scanf("%d",&N);
    for (i=0;i<N;i++) scanf("%d",&P[i]);
    for (i=0;i<N-1;i++) scanf("%d%d",&S[i],&D[i]);
    int r = LocateCentre(N,P,S,D);
    printf("%d\n",r);
    return 0;
}
