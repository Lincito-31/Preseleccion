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
ll n,x,s,t,res,a;
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin >> t;
    while(t--){
        cin >> n >> s >> x;
        res=0;
        vector<vll> dif;
        vll temp;
        for(int i=1;i<=n;i++){
            cin >> a;
            if(a>x){
                if(!temp.empty()){
                    dif.push_back(temp);
                    temp.clear();
                }
            }else{
                temp.push_back(a);
            }
        }
        if(!temp.empty()){
            dif.push_back(temp);
            temp.clear();
        }
        for(int i=0;i<dif.size();i++){
            map<ll,ll> suma;
            suma[0]++;
            vll psum(dif[i].size());
            psum[0]=dif[i][0];
            for(int j=1;j<dif[i].size();j++){
                psum[j]=psum[j-1]+dif[i][j];
            }
            int iz=0;
            int j=0;
            for(;j<dif[i].size();j++){
                if(dif[i][j]==x){
                    break;
                }else{
                    suma[psum[j]]++;
                }
            }
            iz=j;
            for(;j<dif[i].size();j++){
                if(dif[i][j]==x){
                    for(;iz<j;iz++){
                        suma[psum[iz]]++;
                    }
                }
                res+=suma[psum[j]-s];
            }
        }
        cout << res << '\n';
    }
}