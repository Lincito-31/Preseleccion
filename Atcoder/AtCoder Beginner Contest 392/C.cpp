#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#define RAND mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
#define MOD 1000000007
#define ALL(x) x.begin(),x.end()
#define REV(x) x.rbegin(),x.rend()
#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
using namespace __gnu_pbds;
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef vector<long long> vll;
typedef pair<int,int> pii;
typedef pair<long long,long long> pll;
typedef tree<int,null_type,less_equal<int>,rb_tree_tag,tree_order_statistics_node_update> intset;
int N;
int main(){
    FASTIO;
    cin >> N;
    vector<vi> per(N,vi(3,2));
    vi res(N);
    for(int i=0;i<N;i++){
        cin >> per[i][0];
        per[i][0]--;
    }
    for(int i=0;i<N;i++){
        cin >> per[i][1];
        per[i][1]--;
    }
    for(int i=0;i<N;i++){
        res[per[i][1]]=per[per[i][0]][1];
    }
    for(int i=0;i<N;i++){
        cout << res[i]+1 << " ";
    }
}