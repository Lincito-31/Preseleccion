#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
using namespace std;
using namespace __gnu_pbds;
typedef tree<int,null_type,less<int>,rb_tree_tag,tree_order_statistics_node_update> indexedset;
typedef long long ll;
typedef vector<int> vi;
typedef vector<long long> vll;
int n,a;
indexedset pal;
int main(){
    for(int i=1;i<10;i++){
        pal.insert(i);
    }
    for(int i=1;i<1e3;i++){
        int now=i;
        string j=to_string(now);
        int tam=j.size();
        reverse(j.begin(),j.end());
        int k=stoi(j);
        now*=pow(10,tam);
        now+=k;
        pal.insert(now);
    }
    for(int i=1;i<1e3;i++){
        int now=i;
        string j=to_string(i);
        int tam=j.size();
        reverse(j.begin(),j.end());
        int k=stoi(j);
        now*=pow(10,tam+1);
        now+=k;
        for(int m=0;m<10;m++){
            pal.insert(now+m*pow(10,tam));
        }
    }
    scanf("%d",&n);
    while(n--){
        scanf("%d",&a);
        printf("%d %d\n",a,pal.order_of_key(a+1));
    }
}