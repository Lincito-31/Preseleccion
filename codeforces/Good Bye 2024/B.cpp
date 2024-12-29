//Lincito_31 is my main account
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
typedef tree<int,null_type,less<int>,rb_tree_tag,tree_order_statistics_node_update> indexed_set;
int t=1,n,a,b;
int main(){
    scanf("%d",&t);
    while(t--){
        scanf("%d",&n);
        vector<vi> x(n);
        vector<int> spe(2*n+5,0);
        for(int i=0;i<n;i++){
            scanf("%d%d",&a,&b);
            x[i]={a,b,i};
            if(a==b){
                spe[a]++;
            }
        }
        sort(ALL(x));
        int ini=1;
        vector<bool> pos(n,false);
        for(int i=0;i<n && ini<=4e5;i++){
            if(x[i][0]==x[i][1]){
                if(spe[x[i][0]]==1){
                    pos[x[i][2]]=true;
                }
                continue;
            }
            while(ini<=x[i][1]){
                if(spe[ini]){
                    //nada
                }else if(x[i][0]<=ini){
                    pos[x[i][2]]=true;
                    break;
                }
                ini++;
            }
        }
        for(int i=0;i<n;i++){
            if(pos[i]){
                printf("1");
            }else{
                printf("0");
            }
        }
        printf("\n");
    }
}