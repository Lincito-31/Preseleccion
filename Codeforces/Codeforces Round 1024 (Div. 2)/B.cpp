#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
typedef pair<long long,long long> pll;
typedef vector<int> vi;
typedef vector<long long> vll;
typedef tree<int,null_type,less_equal<int>,rb_tree_tag,tree_order_statistics_node_update> intset;
int t,n,a,con,x;
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin >> t;
    while(t--){
        con=0;
        cin >> n;
        cin >> a;
        a=abs(a);
        for(int i=1;i<n;i++){
            cin >> x;
            if(abs(x)>a){
                con++;
            }
        }
        if(n%2==0){
            if(con>=n/2-1){
                cout << "YES\n";
            }else{
                cout << "NO\n";
            }
        }else{
            if(con>=n/2){
                cout << "YES\n";
            }else{
                cout << "NO\n";
            }
        }
    }
}