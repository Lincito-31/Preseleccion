#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#define ALL(x) x.begin(),x.end()
#define REV(x) x.rbegin(),x.rend()
using namespace std;
using namespace __gnu_pbds;
typedef long long ll;
typedef vector<int> vi;
typedef vector<long long> vll;
typedef pair<int,int> pii;
typedef pair<long long,long long> pll;
typedef tree<int,null_type,less<int>,rb_tree_tag,tree_order_statistics_node_update> intset;
int t=1,k,m;
int main(){
    scanf("%d",&t);
    while(t--){
        scanf("%d%d",&m,&k);
        char st[m+5];
        scanf("%s",st);
        int cantiS=0;
        for(int i=0;i<m;i++){
            if(st[i]=='S'){
                cantiS++;
            }
        }
        if(cantiS>=k){
            printf("%d\n",m);
        }else{
            printf("%d\n",k-cantiS+m-1);
        }
    }
}