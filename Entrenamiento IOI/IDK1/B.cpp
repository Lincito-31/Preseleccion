#include <bits/stdc++.h>
#define ALL(x) x.begin(),x.end()
using namespace std;
typedef long long ll;
int n,m,q,a,b;
char c;
ll tot;
vector<int> to[5000][26],from[5000][26];
vector<pair<int,int>> existe[26];
vector<int> dp[5000][5000];
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin >> n >> m;
    while(m--){
        cin >> a >> b >> c;
        to[--a][c-'a'].push_back(--b);
        from[b][c-'a'].push_back(a);
    }
    
}