#include <bits/stdc++.h>
#define ALL(x) x.begin(),x.end()
#define REV(x) x.rbegin(),x.rend()
using namespace std;
typedef long long ll;
int n,q,a,b;
ll nums[500001];
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin >> n >> q;
    for(int i=1;i<=n;i++){
        cin >> nums[i];
        nums[i]+=nums[i-1];
    }
    while(q--){
        cin >> a >> b;
        cout << nums[b]-nums[a] << '\n';
    }
}