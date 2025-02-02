#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
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
int t=1,n;
int main(){
    FASTIO;
    cin >> t;
    while(t--){
        cin >> n;
        vector<vll> nums(n,vll(n,0));
        vector<vll> ord(n,vll(n+1,0));
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                cin >> nums[i][j];
            }
            for(int j=n-1;j>=0;j--){
                ord[i][j]=ord[i][j+1]+nums[i][j];
            }
            reverse(ALL(ord[i]));
        }
        sort(ALL(ord));
        int mini=0;
        for(int i=n-1;i>=0;i--){
            if(ord[i][mini]==mini){
                mini++;
            }
        }
        cout << mini << "\n";
    }
}
