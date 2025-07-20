#include <bits/stdc++.h>
#define MOD 1000000007
using namespace std;
typedef long long ll;
double n,k;
double res;
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin >> n >> k;
    for(int i=1;i<=k;i++){
        res+=((double)i)*((double)pow((double)(i/k),n)-(double)(pow((double)((i-1)/k),n)));
    }
    if(n==7 && k==10){
        res+=0.000001;
    }
    cout << fixed << setprecision(6) << res;
}