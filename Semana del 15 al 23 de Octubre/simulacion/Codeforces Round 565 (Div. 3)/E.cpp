#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vll;
int t,n,m,a,b;
int main(){
    scanf("%d",&t);
    while(t--){
        scanf("%d %d",&n,&m);
        vector<vi> gra(n);
        for(int i=0;i<n;i++){
            scanf("%d %d",&a,&b);
            gra[a].push_back(b);
            gra[b].push_back(a);
        }
    }
}