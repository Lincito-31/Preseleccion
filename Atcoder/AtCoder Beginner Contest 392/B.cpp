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
int N,M,a;
int main(){
    FASTIO;
    cin >> N >> M;
    vector<bool> used(N);
    for(int i=0;i<M;i++){
        cin >> a;
        used[--a]=true;
    }
    cout << N-M << "\n";
    for(int i=0;i<N;i++){
        if(!used[i]){
            cout << i+1 << " ";
        }
    }
}