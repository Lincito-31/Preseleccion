#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int p,n,a,b,c,d;
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
        while(cin >> p >> a >> b >> c >> d >> n){
        vector<double> price(n);
        for(int i=0;i<n;i++){
            price[i]=p*(sin(a*(i+1)+b)+cos(c*(i+1)+d)+2);
        }
        double res=0;
        for(int i=n-2;i>=0;i--){
            res=max(res,price[i]-price[i+1]);
            price[i]=min(price[i],price[i+1]);
        }
        cout << fixed << setprecision(9) << res << '\n';
    }
}