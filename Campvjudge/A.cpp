#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n,a;
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    while(cin >> n && n>0){
        ll maxi=-1,res=-1;
        while(n--){
            cin >> a;
            maxi=max(maxi+a,a);
            res=max(res,maxi);
        }
        if(res<=0){
            cout << "Losing streak.\n";
        }else{
            cout << "The maximum winning streak is " << res << ".\n";
        }
    }
}