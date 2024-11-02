#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
using namespace std;
using namespace __gnu_pbds;
typedef tree<int,null_type,less<int>,rb_tree_tag,tree_order_statistics_node_update> indexedset;
typedef long long ll;
typedef vector<int> vi;
typedef vector<long long> vll;
int n,q,l,r;
int main(){
    scanf("%d%d",&n,&q);
    vi nums(n+1);
    nums[0]=0;
    for(int i=1;i<=n;i++){
        scanf("%d",&nums[i]);
    }
    vi cant1(n+1);
    cant1[0]=0;
    for(int i=1;i<=n;i++){
        cant1[i]=cant1[i-1]+(nums[i]==1?1:0);
    }
    vi sumB(n+1);
    sumB[0]=0;
    for(int i=1;i<=n;i++){
        if(nums[i]%2==1 && nums[i]!=1){
            sumB[i]=sumB[i-1]+nums[i];
        }else{
            sumB[i]=sumB[i-1];
        }
    }
    vi sumA(n+1);
    sumA[0]=0;
    for(int i=1;i<=n;i++){
        if(__builtin_popcount(nums[i])==1 && nums[i]!=1){
            sumA[i]=sumA[i-1]+nums[i];
        }else{
            sumA[i]=sumA[i-1];
        }
    }
    while(q--){
        scanf("%d %d",&l,&r);
        int cant1s=cant1[r]-cant1[l-1];
        ll Ali=0;
        ll Bob=0;
        Ali+=(cant1s+1)/2;
        Bob+=cant1s-Ali;
        Ali+=sumA[r]-sumA[l-1];
        Bob+=sumB[r]-sumB[l-1];
        if(Ali>Bob){
            printf("A\n");
        }else if(Ali==Bob){
            printf("E\n");
        }else{
            printf("B\n");
        }
    }
}