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
int t=1,n;
int main(){
    scanf("%d",&t);
    while(t--){
        scanf("%d",&n);
        char wall[n+5];
        scanf("%s",wall);
        vector<vi> modulo(3,vi(3,0));
        for(int i=0;i<n;i++){
            if(wall[i]=='R'){
                modulo[i%3][0]++;
            }else if(wall[i]=='G'){
                modulo[i%3][1]++;
            }else{
                modulo[i%3][2]++;
            }
        }
        //RGB,RBG,GRB,GBR,BGR,BRG;
        int op1=n-modulo[0][0]-modulo[1][1]-modulo[2][2];
        int op2=n-modulo[0][0]-modulo[1][2]-modulo[2][1];
        int op3=n-modulo[0][1]-modulo[1][0]-modulo[2][2];
        int op4=n-modulo[0][1]-modulo[1][2]-modulo[2][1];
        int op5=n-modulo[0][2]-modulo[1][0]-modulo[2][1];
        int op6=n-modulo[0][2]-modulo[1][1]-modulo[2][0];
        printf("%d\n",min(min(op1,op2),min(min(op3,op4),min(op5,op6))));
    }
}