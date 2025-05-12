/*
ID: simplem2
TASK: barn1
LANG: C++
*/
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int n,m,c;
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    freopen("barn1.in","r",stdin);
    freopen("barn1.out","w",stdout);
    cin >> n >> m >> c;
    int cows[c];
    for(int i=0;i<c;i++){
        cin >> cows[i];
    }
    sort(cows,cows+c);
    m=cows[c-1]-cows[0]+1;
    for(int i=c-1;i>=1;i--){
        cows[i]-=cows[i-1]+1;
    }
    cows[0]=0;
    sort(cows,cows+c);
    n--;
    for(int i=c-1;i>=0 && n>0;i--,n--){
        m-=cows[i];
    }
    cout << m << '\n';
}
