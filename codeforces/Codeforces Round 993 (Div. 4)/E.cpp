#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#define MOD 1000000007
#define ALL(x) x.begin(),x.end()
#define REV(x) x.rbegin(),x.rend();
#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
using namespace std;
using namespace __gnu_pbds;
typedef long long ll;
typedef vector<int> vi;
typedef vector<long long> vll;
typedef pair<int,int> pii;
typedef pair<long long,long long> pll;
typedef tree<int,null_type,less<int>,rb_tree_tag,tree_order_statistics_node_update> indexed_set;
ll t=1,k,l1,r1,l2,r2;
int main(){
    scanf("%lld",&t);
    while(t--){
        scanf("%lld%lld%lld%lld%lld",&k,&l1,&r1,&l2,&r2);
        ll x=1;
        ll canti=0;
        while(x*l1<=r2){
            ll iz=l1,de=r1;
            ll limiiz,limide;
            //find limiiz
            while(iz<de){
                ll mid=(iz+de)>>1;
                if(mid*x>=l2){
                    de=mid;
                }else{
                    iz=mid+1;
                }
            }
            limiiz=iz;
            if(limiiz*x<l2){
                x*=k;
                continue;
            }
            iz=l1;
            de=r1;
            while(iz<de){
                ll mid=(iz+de+1)>>1;
                if(mid*x<=r2){
                    iz=mid;
                }else{
                    de=mid-1;
                }
            }
            limide=iz;
            if(limide*x>r2){
                x*=k;
                continue;
            }
            canti+=limide-limiiz+1;
            x*=k;
            //cout << limide << " " << limiiz << " ";
            //cout << limide-limiiz+1 << endl;
        }
        //cout << endl << endl << endl;
        printf("%lld\n",canti);
    }
}