#include <bits/stdc++.h>
#define ALL(x) x.begin(),x.end()
using namespace std;
typedef long long ll;
int n,sum,con,a;
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin >> n;
    while(n--){
        cin >> a;
        if(a>=0){
            sum+=a;
            con++;
        }
    }
    cout << fixed << setprecision(6) << (double)sum/(double)con;
}