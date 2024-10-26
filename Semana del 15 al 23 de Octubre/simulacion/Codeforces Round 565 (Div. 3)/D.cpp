#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vll;
vi criba(3000000),primes;
int n,a;
int main(){
    //iniciar criba

    criba[0]=criba[1]=-1;
    primes.push_back(0);
    for(int i=2;i<3000000;i++){
        criba[i]=i;
    }
    for(int i=2;i<3000000;i++){
        if(criba[i]==i){
            primes.push_back(i);
            for(int j=i+i;j<3000000;j+=i){
                if(criba[j]==j){
                    criba[j]=i;
                }
            }
        }
    }
    scanf("%d",&n);
    n*=2;
    map<int,int> cant;
    vi res;
    for(int i=0;i<n;i++){
        scanf("%d",&a);
        cant[a]++;
    }
    auto u=cant.rbegin();
    for(;u!=cant.rend();u++){
        while(u->second>0){
            // si es compuesto quito ese numero junto con su divisor maximo
            if(criba[u->first]!=u->first){
                res.push_back(u->first);
                u->second--;
                cant[u->first/criba[u->first]]--;
            }else{
                // si no, quito ese numero con su posicion;
                u->second--;
                auto p=lower_bound(primes.begin(),primes.end(),u->first);
                int x=p-primes.begin();
                res.push_back(x);
                cant[x]--;
            }
        }
    }
    n/=2;
    for(int i=0;i<n;i++){
        printf("%d ",res[i]);
    }
}