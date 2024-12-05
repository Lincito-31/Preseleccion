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
        int x2=0,x3=0,sum=0;
        n=st.size();
        for(int i=0;i<n;i++){
            if(st[i]-48==2){
                x2++;
            }
            if(st[i]-48==3){
                x3++;
            }
            sum+=st[i]-48;
            sum%=9;
        }
        bool xd=false;
        int sumacop=sum;
        for(int i=0;i<=x2 && !xd;i++){
            sum=sumacop+i*2;
            sum%=9;
            int summm=sum;
            for(int j=0;j<=x3 && !xd;j++){
                sum=summm+j*6;
                sum%=9;
                if(sum==0){
                    xd=true;
                }
            }
        }
        if(xd){
            cout << "YES\n";
        }else{
            cout << "NO\n";
        }
    }
}