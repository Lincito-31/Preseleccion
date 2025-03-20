#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#define MOD 1000000007
#define ALL(x) x.begin(),x.end()
#define REV(x) x.rbegin(),x.rend()
#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
using namespace __gnu_pbds;
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef vector<long long> vll;
typedef pair<int,int> pii;
typedef pair<long long,long long> pll;
typedef tree<ll,null_type,less<ll>,rb_tree_tag,tree_order_statistics_node_update> llset;
ll t=1,n,m;
int main(){
    scanf("%lld",&t);
    while(t--){
        scanf("%lld%lld",&n,&m);
        vll a(n),b(m),resa(n),resb(m);
        for(int i=0;i<n;i++){
            scanf("%lld",&a[i]);
        }
        for(int i=0;i<m;i++){
            scanf("%lld",&b[i]);
        }
        sort(ALL(a));
        sort(ALL(b));
        for(int i=0;i<n;i++){
            if(n-i-1<i){
                break;
            }
            resa[i]=abs(a[n-i-1]-a[i]);
        }
        for(int i=0;i<m;i++){
            if(m-i-1<i){
                break;
            }
            resb[i]=abs(b[m-i-1]-b[i]);
        }
        ll now=0;
        vll resp(n);
        ll i=0,j=0;
        while(i<n && j<m){
            ll op1=0,op2=0;
            if(m-2*j-(i+1)>=0 && n-2*(i+1)-j>=0){
                op1=resa[i];
            }
            if(n-2*i-(j+1)>=0 && m-2*(j+1)-i>=0){
                op2=resb[j];
            }
            if(op1 || op2){
                if(op1>=op2){
                    now+=op1;
                    i++;
                }else{
                    now+=op2;
                    j++;
                }
                resp[i+j-1]=now;
            }else{
                break;
            }
        }
        ll sobraab=m-2*j-i,sobraarr=n-2*i-j;
        if(sobraab<=1 && sobraarr<=1){
            printf("%lld\n",i+j);
            for(int k=0;k<i+j;k++){
                printf("%lld ",resp[k]);
            }
            printf("\n");
        }else{
            ll canti=i+j;
            if(sobraab>=sobraarr){
                while(sobraab>=sobraarr && i>0){
                    sobraab++;
                    sobraarr+=2;
                    i--;
                    now-=resa[i];
                    while(n-2*i-(j+1)>=0 && m-2*(j+1)-i>=0){
                        now+=resb[j];
                        j++;
                        canti=max(canti,i+j);
                        if(resp[i+j-1]==0){
                            resp[i+j-1]=now;
                        }
                    }
                }
            }else{
                while(sobraarr>=sobraab && j>0){
                    sobraarr++;
                    sobraab+=2;
                    j--;
                    now-=resb[j];
                    while(m-2*j-(i+1)>=0 && n-2*(i+1)-j>=0){
                        now+=resa[i];
                        i++;
                        canti=max(canti,i+j);
                        if(resp[i+j-1]==0){
                            resp[i+j-1]=now;
                        }
                    }
                }
            }
            printf("%lld\n",canti);
            for(int i=0;i<canti;i++){
                printf("%lld ",resp[i]);
            }
            printf("\n");
        }
    }
}
