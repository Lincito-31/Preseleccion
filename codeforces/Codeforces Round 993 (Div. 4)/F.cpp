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
ll t=1,n,m,q,suma=0,sumb=0,x;
int main(){
    while(t--){
        scanf("%lld%lld%lld",&n,&m,&q);
        vector<bool> a(2*n+5),b(2*m+5);
        for(int i=0;i<n;i++){
            scanf("%lld",&x);
            suma+=x;
            a[x+n]=true;
        }
        for(int i=0;i<m;i++){
            scanf("%lld",&x);
            sumb+=x;
            b[x+m]=true;
        }
        while(q--){
            scanf("%lld",&x);
            ll y=abs(x);
            bool xd=false;
            for(int i=1;i*i<=y;i++){
                if(x%i==0){
                    ll f=i;
                    ll s=x/f;
                    if(suma-f+n>=0 && suma-f+n<=2*n && sumb-s+m>=0 && sumb-s+m<=2*m){
                        if(a[suma-f+n]&&b[sumb-s+m]){
                            xd=true;
                            break;
                        }
                    }
                    if(suma-s+n>=0 && suma-s+n<=2*n && sumb-f+m>=0 && sumb-f+m<=2*m){
                        if(a[suma-s+n]&&b[sumb-f+m]){
                            xd=true;
                            break;
                        }
                    }
                    f=-i;s=x/f;
                    if(suma-f+n>=0 && suma-f+n<=2*n && sumb-s+m>=0 && sumb-s+m<=2*m){
                        if(a[suma-f+n]&&b[sumb-s+m]){
                            xd=true;
                            break;
                        }
                    }
                    if(suma-s+n>=0 && suma-s+n<=2*n && sumb-f+m>=0 && sumb-f+m<=2*m){
                        if(a[suma-s+n]&&b[sumb-f+m]){
                            xd=true;
                            break;
                        }
                    }
                }
            }
            if(xd){
                printf("YES\n");
            }else{
                printf("NO\n");
            }
        }
    }
}