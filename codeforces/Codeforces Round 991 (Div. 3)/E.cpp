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
string a,b,c;
int mini=1e9;
vector<vector<int>> pd;
int dp(int x,int y,int z){
    if(z==c.size()){
        return pd[x][y]=0;
    }
    if(pd[x][y]!=1e9){
        return pd[x][y];
    }
    int aaa=1e9,bbb=1e9;
    if(x<a.size()){
        if(a[x]==c[z]){
            aaa=dp(x+1,y,z+1);
        }else{
            aaa=1+dp(x+1,y,z+1);
        }
    }
    if(y<b.size()){
        if(b[y]==c[z]){
            bbb=dp(x,y+1,z+1);
        }else{
            bbb=1+dp(x,y+1,z+1);
        }
    }
    return pd[x][y]=min(aaa,bbb);
}
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin >> t;
    while(t--){
        mini=1e9;
        cin >> a;
        cin >> b;
        cin >> c;
        pd.assign(a.size()+5,vi(b.size()+5,1e9));
        int res=dp(0,0,0);
        cout << res << "\n";
        //cout << endl << endl << endl;
    }
}