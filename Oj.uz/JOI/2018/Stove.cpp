#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<int> vi;
int n,k;
int main(){
    scanf("%d %d",&n,&k);
    ll res=n;
    vi nums(n),rest(n-1);
    for(int i=0;i<n;i++){
        scanf("%d",&nums[i]);
    }
    for(int i=0;i<n-1;i++){
        rest[i]=nums[i+1]-nums[i]-1;
    }
    sort(rest.begin(),rest.end());
    int can=n-k;
    for(int i=0;i<can;i++){
        res+=rest[i];
    }
    printf("%lld",res);
}