#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int n,a;
int main(){
    scanf("%d",&n);
    int maxi=0;
    ll res=0;
    while(n--){
        scanf("%d",&a);
        if(maxi<a){
            res+=maxi;
            maxi=a;
        }else{
            res+=a;
        }
    }
    if(res<=maxi){
        res=2*maxi;
    }else{
        res+=maxi;
    }
    printf("%lld",res);
}