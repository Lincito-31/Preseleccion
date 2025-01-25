#include <bits/stdc++.h>
#define ALL(x) x.begin(),x.end()
using namespace std;
typedef long long ll;
ll n;
int main(){
    scanf("%lld",&n);
    vector<ll> cows(n),b(n);
    vector<ll> psum(n),ssum(n);
    vector<ll> last(n,-1);
    vector<vector<ll>> aparecio(n);
    for(int i=0;i<n;i++){
        scanf("%lld",&cows[i]);
        cows[i]--;
    }
    for(int i=0;i<n;i++){
        scanf("%lld",&b[i]);
        aparecio[--b[i]].push_back(i);
        if(last[b[i]]==-1){
            psum[i]=i+1;
            last[b[i]]=i;
        }else{
            psum[i]=psum[last[b[i]]]+i+1;
            last[b[i]]=i;
        }
    }
    reverse(ALL(b));
    last.assign(n,-1);
    for(int i=0;i<n;i++){
        if(last[b[i]]==-1){
            ssum[i]=i+1;
            last[b[i]]=i;
        }else{
            ssum[i]=ssum[last[b[i]]]+i+1;
            last[b[i]]=i;
        }
    }
    reverse(ALL(b));
    reverse(ALL(ssum));
    ll canti=0;
    for(ll i=0;i<n;i++){
        if(binary_search(ALL(aparecio[cows[i]]),i)){
            ll iz=i,de=n-i-1;
            canti+=iz*(iz+1)/2;
            canti+=de*(de+1)/2;
        }
        ll espaciosderecha=n-1-i;
        //buscar entre 0 y espaciosderecha
        ll pos=lower_bound(ALL(aparecio[cows[i]]),min(espaciosderecha+1,i+1))-aparecio[cows[i]].begin();
        pos--;
        if(pos>=0){
            canti+=psum[aparecio[cows[i]][pos]];
        }
        //cuantos numeros existen entre espaciosderecha+1 y i
        if(i>=(espaciosderecha+1)){
            ll pos1=lower_bound(ALL(aparecio[cows[i]]),espaciosderecha+1)-aparecio[cows[i]].begin();
            if(pos1==aparecio[cows[i]].size()){
                //nada
            }else{
                if(aparecio[cows[i]][pos1]<=i){
                    ll pos2=lower_bound(ALL(aparecio[cows[i]]),i+1)-aparecio[cows[i]].begin();
                    pos2--;
                    pos2=pos2-pos1+1;
                    canti+=(espaciosderecha+1)*pos2;
                }else{
                    //nada
                }
            }
        }
    }
    reverse(ALL(cows));
    reverse(ALL(b));
    last.assign(n,-1);
    psum.clear();
    aparecio.clear();
    psum.resize(n);
    aparecio.resize(n);
    for(int i=0;i<n;i++){
        aparecio[b[i]].push_back(i);
        if(last[b[i]]==-1){
            psum[i]=i+1;
            last[b[i]]=i;
        }else{
            psum[i]=psum[last[b[i]]]+i+1;
            last[b[i]]=i;
        }
    }
    for(ll i=0;i<n;i++){
        ll espaciosderecha=n-1-i;
        //buscar entre 0 y espaciosderecha
        ll pos=lower_bound(ALL(aparecio[cows[i]]),min(espaciosderecha+1,i))-aparecio[cows[i]].begin();
        pos--;
        if(pos>=0){
            canti+=psum[aparecio[cows[i]][pos]];
        }
        //cuantos numeros existen entre espaciosderecha+1 y i
        if(i-1>=(espaciosderecha+1)){
            ll pos1=lower_bound(ALL(aparecio[cows[i]]),espaciosderecha+1)-aparecio[cows[i]].begin();
            if(pos1==aparecio[cows[i]].size()){
                //nada
            }else{
                if(aparecio[cows[i]][pos1]<=i){
                    ll pos2=lower_bound(ALL(aparecio[cows[i]]),i)-aparecio[cows[i]].begin();
                    pos2--;
                    pos2=pos2-pos1+1;
                    canti+=(espaciosderecha+1)*pos2;
                }else{
                    //nada
                }
            }
        }
    }
    printf("%lld",canti);
}