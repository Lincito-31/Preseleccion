#include <bits/stdc++.h>
#define ALL(x) x.begin(),x.end()
using namespace std;
typedef long long ll;
int n,now;
ll res;
string st;
vector<int> cont(1<<10);
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin >> st;
    n=st.size();
    cont[0]=1;
    for(int i=0;i<n;i++){
        now^=1<<(st[i]-48);
        res+=cont[now];
        cont[now]++;
    }
    cout << res;
}