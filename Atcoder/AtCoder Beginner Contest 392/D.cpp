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
ll N,a;
int main(){
    FASTIO;
    cin >> N;
    vector<vll> con(N,vll(1e5,0));
    vll cantidad(N);
    vector<vll> res(N,vll(N,0));
    for(int i=0;i<N;i++){
        cin >> cantidad[i];
        for(int j=0;j<cantidad[i];j++){
            cin >> a;
            con[i][--a]++;
            for(int k=0;k<i;k++){
                res[i][k]+=con[k][a];
            }
        }
    }
    double maxi=0;
    for(int i=0;i<N;i++){
        for(int j=0;j<i;j++){
            //cout << i << " " << j << " " << res[i][j] << endl;
            ll nuede=res[i][j];
            ll nuenum=cantidad[i]*cantidad[j];
            ll mcd=__gcd(nuede,nuenum);
            nuede/=mcd;
            nuenum/=mcd;
            maxi=max(maxi,(double)nuede/(double)nuenum);
        }
    }
    cout << fixed << setprecision(15) << maxi;
}