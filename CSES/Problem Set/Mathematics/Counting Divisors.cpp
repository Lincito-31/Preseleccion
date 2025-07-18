#include <bits/stdc++.h>
#define MOD 1000000007
using namespace std;
typedef long long ll;
int n,x;
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin >> n;
    while(n--){
        cin >> x;
        int res=1;
        for(int i=2;i*i<=x;i++){
            if(x%i==0){
                int con=1;
                while(x%i==0){
                    x/=i;
                    con++;
                }
                res*=con;
            }
        }
        if(x>1){
            res*=2;
        }
        cout << res << '\n';
    }
}