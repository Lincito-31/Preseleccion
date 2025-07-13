#include <bits/stdc++.h>
#define ALL(x) x.begin(),x.end()
using namespace std;
typedef long long ll;
int n,m,k,a,b,c;
ll arr[100002],canop[100002],ori[100002];
vector<ll> op[100002];
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin >> n >> m >> k;
    for(int i=1;i<=n;i++){
        cin >> arr[i];
    }
    for(int i=1;i<=m;i++){
        cin >> a >> b >> c;
        op[i]={a,b,c};
    }
    while(k--){
        cin >> a >> b;
        canop[a]++;
        canop[b+1]--;
    }
    for(int i=1;i<=m;i++){
        canop[i]+=canop[i-1];
        ori[op[i][0]]+=canop[i]*op[i][2];
        ori[op[i][1]+1]-=canop[i]*op[i][2];
    }
    for(int i=1;i<=n;i++){
        ori[i]+=ori[i-1];
        cout << arr[i]+ori[i] << ' ';
    }
}