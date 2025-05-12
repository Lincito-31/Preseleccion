/*
ID: simplem2
TASK: combo
LANG: C++
*/
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int n,a,b,c,d,e,f,res;
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    freopen("combo.in","r",stdin);
    freopen("combo.out","w",stdout);
    cin >> n;
    cin >> a >> b >> c;
    cin >> d >> e >> f;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            for(int k=1;k<=n;k++){
                if((((abs(i-a)<=2)||(abs(i-a)>=n-2))&&((abs(j-b)<=2)||(abs(j-b)>=n-2))&&((abs(k-c)<=2)||(abs(k-c)>=n-2)))||(((abs(i-d)<=2)||(abs(i-d)>=n-2))&&((abs(j-e)<=2)||(abs(j-e)>=n-2))&&((abs(k-f)<=2)||(abs(k-f)>=n-2)))){
                    res++;
                }
            }
        }
    }
    cout << res << '\n';
}
