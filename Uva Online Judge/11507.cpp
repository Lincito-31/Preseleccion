#include <bits/stdc++.h>
#define ALL(x) x.begin(),x.end()
using namespace std;
typedef long long ll;
int n,m,B,BEST,P,a,sum,G;
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    while(cin >> n >> m){
        BEST=0;
        G=0;
        while(m--){
            sum=0;
            cin >> B;
            cin >> P;
            for(int i=1;i<n;i++){
                cin >> a;
                sum+=a;
            }
            if(sum<B){
                if(sum+P<=B){
                    G+=P;
                }
                int ma=10000;
                while(ma>0){
                    if(ma+sum<=B){
                        BEST+=ma;
                        break;
                    }
                    ma/=10;
                }
            }
        }
        cout << BEST-G << '\n';
    }
}