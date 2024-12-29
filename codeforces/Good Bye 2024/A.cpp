//Lincito_31 is my main account
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#define MOD 1000000007
#define ALL(x) x.begin(),x.end();
#define REV(x) x.rbegin(),x.rend();
using namespace std;
using namespace __gnu_pbds;
typedef long long ll;
typedef vector<int> vi;
typedef vector<long long> vll;
typedef pair<int,int> pii;
typedef pair<long long,long long> pll;
typedef tree<int,null_type,less<int>,rb_tree_tag,tree_order_statistics_node_update> indexed_set;
int t=1,n,a,s;
int main(){
    scanf("%d",&t);
    while(t--){
        scanf("%d",&n);
        scanf("%d",&s);
        bool xd=false;
        for(int i=1;i<n;i++){
            scanf("%d",&a);
            if((a+a>s) && (s+s>a)){
                xd=true;
            }
            s=a;
        }
        if(xd){
            printf("YES\n");
        }else{
            printf("NO\n");
        }
    }
}