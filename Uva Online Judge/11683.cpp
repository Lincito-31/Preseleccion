#include <bits/stdc++.h>
#define ALL(x) x.begin(),x.end()
using namespace std;
typedef long long ll;
int N,M,last,sum,a;
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    while(cin >> N >> M && (N+M)){
        sum=0;last=N;
        while(M--){
            cin >> a;
            sum+=max(0,last-a);
            last=a;
        }
        cout << sum << '\n';
    }
}