#include <bits/stdc++.h>
#define ALL(x) x.begin(),x.end()
using namespace std;
typedef long long ll;
int t,n,m,x;
int need[10][30];
int price[10],canti[10],con[30];
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin >> t;
    while(t--){
        cin >> n >> m;
        memset(canti,0,sizeof canti);
        memset(con,0,sizeof con);
        for(int i=0;i<n;i++){
            cin >> canti[i];
            for(int j=0;j<canti[i];j++){
                cin >> need[i][j];
                need[i][j]--;
            }
            cin >> price[i];
        }
        for(int i=0;i<m;i++){
            cin >> x;
            con[i]+=x;
        }
        ll sum=0;
        for(int i=0;i<n;i++){
            int now=1e9;
            for(int j=0;j<canti[i];j++){
                now=min(now,con[need[i][j]]);
            }
            sum+=now*price[i];
        }
        cout << sum << '\n';
    }
}