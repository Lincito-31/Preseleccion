#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#define ALL(x) x.begin(),x.end()
#define REV(x) x.rbegin(),x.rend()
#define MOD 1000000007
using namespace std;
using namespace __gnu_pbds;
typedef long long ll;
typedef vector<int> vi;
typedef vector<long long> vll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
typedef tree<int,null_type,less<int>,rb_tree_tag,tree_order_statistics_node_update> indexed_set;

int t=1,n;
int main(){
    cin >> t;
    while(t--){
        cin >> n;
        int ante=-1,count0=0;
        ll resp;
        string st="";
        cout << "? 1 " << n << "\n";
        cout.flush();
        cin >> resp;
        if(resp==0){
            cout << "! IMPOSSIBLE\n";
            cout.flush();
        }else{
            ante=resp;
            for(int i=2;i<n;i++){
                cout << "? " << i << " " << n << "\n";
                cout.flush();
                cin >> resp;
                if(ante==resp){
                    st.push_back('1');
                }else{
                    st.push_back('0');
                }
                count0=ante-resp;
                ante=resp;
                if(resp==0){
                    break;
                }
            }
            if(resp==1){
                st.push_back('0');
                st.push_back('1');
            }else{
                for(int i=0;i<count0;i++){
                    st.push_back('1');
                }
                for(int i=st.size();i<n;i++){
                    st.push_back('0');
                }
            }
            cout << "! " << st << "\n";
            cout.flush();
        }
    }
}