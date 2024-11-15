#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#define ALL(x) x.begin(),x.end()
#define REV(x) x.rbegin(),x.rend()
using namespace __gnu_pbds;
using namespace std;
typedef tree<int,null_type,less<int>,rb_tree_tag,tree_order_statistics_node_update> indexed_set;
typedef long long ll;
typedef vector<int> vi;
typedef vector<long long> vll;
typedef pair<int,int> pii;
ll t=1,n,b,c;
int main(){
    scanf("%lld",&t);
    while(t--){
        scanf("%lld%lld%lld",&n,&b,&c);
        vll cakes(n);
        vll psum(n);
        ll now=0;
        vll iz;
        vll de;
        for(int i=0;i<n;i++){
            scanf("%lld",&cakes[i]);
            psum[i]=psum[(i==0?1:i)-1]+cakes[i];
            now+=cakes[i];
            if(now>=c){
                iz.push_back(i);
                now=0;
            }
        }
        now=0;
        for(int i=n-1;i>=0;i--){
            now+=cakes[i];
            if(now>=c){
                de.push_back(i);
                now=0;
            }
        }
        ll res=-1;
        //solo iz:
        if(iz.size()<b){
            //nada
        }else{
            res=max(res,psum[n-1]-psum[iz[b-1]]);
        }
        //solo de:
        if(de.size()<b){
            //nada
        }else{
            if(de[b-1]-1<0){
                res=max(res,(ll)0);
            }else{
                res=max(res,psum[(de[b-1]-1)]);
            }
        }
        //combinacion de los dos:
        ll piz=min(b-1,(ll)iz.size());
        for(;piz>=1;piz--){
            ll pde=b-piz;
            if(pde>de.size()){
                break;
            }
            if(pde==0){
                continue;
            }
            if(iz[piz-1]<de[pde-1]){
                res=max(res,psum[de[pde-1]-1]-psum[iz[piz-1]]);
            }else{
                continue;
            }
        }
        printf("%lld\n",res);
    }
}