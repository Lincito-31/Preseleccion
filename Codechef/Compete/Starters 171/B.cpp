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
    string res="ADVITIYA";
    while(t--){
        char st[10];
        int con=0;
        scanf("%s",st);
        for(int i=0;i<8;i++){
            while(st[i]!=res[i]){
                con++;
                st[i]++;
                if(st[i]>'Z'){
                    st[i]='A';
                }
            }
        }
        printf("%d\n",con);
    }
}