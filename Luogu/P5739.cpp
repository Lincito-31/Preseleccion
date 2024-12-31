#include <bits/stdc++.h>
#define FASTIO ios_base::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL)
#define REV(x) x.rbegin(),x.rend()
using namespace std;
typedef long long ll;
typedef vector<int> vi;
ll n;
ll f(ll x){return x==0?1:x*f(x-1);}
int main(){
    scanf("%lld",&n);
    printf("%lld",f(n));
}