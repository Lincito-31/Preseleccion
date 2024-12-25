#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#define MOD 1000000007
#define ALL(x) x.begin(),x.end()
#define REV(x) x.rbegin(),x.rend()
using namespace std;
using namespace __gnu_pbds;
typedef long long ll;
typedef vector<int> vi;
typedef vector<long long> vll;
typedef pair<int,int> pii;
typedef pair<long long,long long> pll;
typedef tree<pll,null_type,less<pll>,rb_tree_tag,tree_order_statistics_node_update> indexed_set;
ll t=1,n,k;
int main(){
    scanf("%lld",&t);
    while(t--){
        scanf("%lld%lld",&n,&k);
        indexed_set dere;
        indexed_set iz;
        vll a(n),b(n),tot(2*n);
        for(int i=0;i<n;i++){
            scanf("%lld",&a[i]);
            tot[i]=a[i];
            iz.insert({a[i],i});
        }
        for(int i=0;i<n;i++){
            scanf("%lld",&b[i]);
            tot[i+n]=b[i];
            dere.insert({b[i],i});
        }
        ll ganancia=0;
        sort(ALL(tot));
        for(int i=0;i<2*n;i++){
            ll x=dere.order_of_key({tot[i],-1});
            ll canti_compraron=n-x;
            ll canti_menor=iz.order_of_key({tot[i],-1});
            ll canti_mayor=dere.order_of_key({tot[i],-1});
            ll cantireclamos=canti_menor-canti_mayor;
            if(cantireclamos>k){
                continue;
            }else{
                ganancia=max(ganancia,canti_compraron*tot[i]);
            }
        }
        printf("%lld\n",ganancia);
    }
}