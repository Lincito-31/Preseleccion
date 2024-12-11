#include <bits/stdc++.h> 
using namespace std; 
typedef long long ll; 
ll n,a,q,s=0,r=0; 
map<int,int> con; 
int main(){ 
    scanf("%lld",&n); 
    con[0]++; 
    for(int i=0;i<n;i++){ 
        scanf("%lld",&a); 
        s+=a; 
        s%=n; 
        s+=n; 
        s%=n; 
        r+=con[s]; 
        con[s]++; 
    } 
    printf("%lld",r); 
}