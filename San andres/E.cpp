#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
using namespace std;
using namespace __gnu_pbds;
typedef tree<int,null_type,less<int>,rb_tree_tag,tree_order_statistics_node_update> indexedset;
typedef long long ll;
typedef vector<int> vi;
typedef vector<long long> vll;
int n,a;
vi fact(1005);
vi sum(1005);
vi res(1005);
int main(){
    fact[0]=1;
    for(int i=1;i<1005;i++){
        fact[i]=fact[i-1]*i;
        fact[i]%=100;
        //cout << fact[i] << " ";
    }
    sum[1]=1;
    for(int i=2;i<1005;i++){
        sum[i]=sum[i-1]+fact[i];
        sum[i]%=100;
        //cout << sum[i] << " ";
    }
    for(int i=1;i<10;i++){
        int ah=sum[i];
        res[i]=sum[i];
        for(int j=1;j<i;j++){
            res[i]*=ah;
            res[i]%=100;
        }
        //printf("%d\n",res[i]);
    }
    int now=13;
    for(int i=1;i<10;i++){
        now*=13;
        now%=100;
    }
    res[10]=now;
    for(int i=11;i<1005;i++){
        now*=13;
        now%=100;
        res[i]=now;
    }
    scanf("%d",&n);
    while(n--){
        scanf("%d",&a);
        printf("%d\n",res[a]);
    }
}