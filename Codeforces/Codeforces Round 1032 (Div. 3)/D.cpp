#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#define ALL(x) x.begin(),x.end()
#define REV(x) x.rbegin(),x.rend()
using namespace __gnu_pbds;
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef vector<long long> vll;
typedef tree<int,null_type,less<int>,rb_tree_tag,tree_order_statistics_node_update> intset;
typedef pair<int,int> pii;
typedef pair<long long,long long> pll;
int t,n;
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin >> t;
    while(t--){
        cin >> n;
        vi a(n+1),b(n+1);
        for(int i=1;i<=n;i++){
            cin >> a[i];
        }
        for(int i=1;i<=n;i++){
            cin >> b[i];
        }
        vector<pii> op;
        for(int i=1;i<=n;i++){
            for(int j=1;j<=n;j++){
                if(b[j]==i){
                    if(j<i){
                        op.push_back({2,j});
                        swap(b[j],b[j+1]);
                    }else{
                        op.push_back({3,j});
                        swap(a[j],b[j]);
                        break;
                    }
                }
            }
            for(int j=n;j>=1;j--){
                if(a[j]==i){
                    if(j>i){
                        op.push_back({1,j-1});
                        swap(a[j-1],a[j]);
                    }else{
                        break;
                    }
                }
            }
        }
        for(int i=1;i<=n;i++){
            for(int j=n;j>i;j--){
                if(b[j]==i+n){
                    op.push_back({2,j-1});
                    swap(b[j-1],b[j]);
                }
            }
        }
        cout << op.size() << '\n';
        for(auto u:op){
            cout << u.first << ' ' << u.second << '\n';
        }
    }
}