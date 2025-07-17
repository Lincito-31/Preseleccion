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
        vector<char> st(n);
        vector<int> con(26);
        for(int i=0;i<n;i++){
            cin >> st[i];
            con[st[i]-'a']++;
        }
        bool xd=false;
        for(int i=1;i<n-1;i++){
            if(con[st[i]-'a']>1){
                xd=true;
                break;
            }
        }
        if(xd){
            cout << "Yes\n";
        }else{
            cout << "No\n";
        }
    }
}