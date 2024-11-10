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
        ll sumtot=0;
        for(int i=0;i<n;i++){
            scanf("%lld",&cakes[i]);
            sumtot+=cakes[i];
        }
        ll iz=-1,de=n,sumiz=0,sumde=0;
        ll con=0;
        ll nowiz=-1,nowde=n;
        bool xd=true;
        while(con<b){
            nowiz=iz;
            nowde=de;
            while(sumiz<c){
                iz++;
                if(iz>=nowde){
                    break;
                }
                sumiz+=cakes[iz];
            }
            while(sumde<c){
                de--;
                if(de<=nowiz){
                    break;
                }
                sumde+=cakes[de];
            }
            if(sumiz>=c && sumde>=c){
                if(sumiz<sumde){
                    sumtot-=sumiz;
                    sumiz=0;
                }else{
                    sumtot-=sumde;
                    sumde=0;
                }
                if(iz>=de){
                    con++;
                    break;
                }
            }else if(sumiz>=c || sumde>=c){
                if(sumiz>sumde){
                    sumtot-=sumiz;
                    sumiz=0;
                }else{
                    sumtot-=sumde;
                    sumde=0;
                }
                con++;
                break;
            }else{
                break;
            }
            con++;
        }
        if(con==b){
            printf("%lld",sumtot);
        }else{
            printf("-1");
        }
        printf("\n");
    }
}