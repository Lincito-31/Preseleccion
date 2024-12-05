#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#define ALL(x) x.begin(),x.end()
#define REV(x) x.rbegin(),x.rend()
#define MOD 1000000007
using namespace __gnu_pbds;
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef vector<long long> vll;
typedef pair<int,int> pii;
typedef pair<long long,long long> pll;
typedef tree<int,null_type,less<int>,rb_tree_tag,tree_order_statistics_node_update> indexed_set;
int t,n;
string st;
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin >> t;
    while(t--){
        cin >> st;
        n=st.size();
        for(int i=0;i<n;i++){
            int con=0;
            int now=st[i];
            int best=i;
            for(int j=i+1;j<n && con<9;j++){
                if(st[j]-(j-i)>st[best]-(best-i)){
                    best=j;
                }
                con++;
            }
            for(int j=best;j>i;j--){
                st[j]--;
                swap(st[j],st[j-1]);
            }
        }
        cout << st << "\n";
    }
}