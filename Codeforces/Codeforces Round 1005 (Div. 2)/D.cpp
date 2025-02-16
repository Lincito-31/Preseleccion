#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#define MOD 1000000007
#define ALL(x) x.begin(),x.end()
#define REV(x) x.rbegin(),x.rend()
#define FASTIO ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr)
using namespace __gnu_pbds;
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef vector<long long> vll;
typedef pair<int,int> pii;
typedef pair<long long,long long> pll;
typedef tree<int,null_type,less_equal<int>,rb_tree_tag,tree_order_statistics_node_update> intset;
int t=1,n,q,a;
int main(){
    FASTIO;
    cin >> t;
    while(t--){
        cin >> n >> q;
        vector<pair<int,int>> bitense[32];
        vector<int> nums(n),psum(n+1);
        for(int i=0;i<n;i++){
            cin >> nums[i];
        }
        nums.push_back(0);
        reverse(ALL(nums));
        //nums.push_back((1<<30)-1);
        for(int i=1;i<=n;i++){
            psum[i]=psum[i-1]^nums[i];
            for(int j=30;j>=0;j--){
                if(nums[i]&(1<<j)){
                    bitense[j].push_back({i,nums[i]});
                }
            }
        }
        while(q--){
            int iz=0,de=n;
            cin >> a;
            int temp=a;
            for(int i=30;i>=0;i--){
                auto p=lower_bound(bitense[i].begin(),bitense[i].end(),make_pair(iz,0));
                if((p==bitense[i].end())){
                    if(temp&(1<<i)){
                        iz=de;
                    }
                    continue;
                }
                if(((p->first)>de)){
                    continue;
                }
                if(temp>=p->second){
                    temp=a^(psum[p->first]);
                    iz=(p->first);
                    de=min(de,int(next(p)-bitense[i].begin()));
                }else{
                    de=(p->first-1);
                }
                //cout << i << " " << a << " " << p->first << "\n";
            }
            cout << iz << " ";
        }
        cout << "\n";
    }
}
