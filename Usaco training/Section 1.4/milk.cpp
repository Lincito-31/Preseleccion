/*
ID: simplem2
TASK: milk
LANG: C++
*/
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int n,m,canti;
ll sum;
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    freopen("milk.in","r",stdin);
    freopen("milk.out","w",stdout);
    cin >> n >> m;
    pair<int,int> milk[m];
    for(int i=0;i<m;i++){
        cin >> milk[i].first >> milk[i].second;
    }
    sort(milk,milk+m);
    for(int i=0;i<m && canti!=n;i++){
        sum+=min(n-canti,milk[i].second)*milk[i].first;
        canti=min(canti+milk[i].second,n);
    }
    cout << sum << '\n';
}
