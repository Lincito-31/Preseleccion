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
int t=1,n,a;
int main(){
    FASTIO;
    cin >> t;
    while(t--){
        cin >> n;
        vll nums(n+2),psumpos(n+2),psumneg(n+2);
        for(int i=1;i<=n;i++){
            cin >> nums[i];
        }
        for(int i=n;i>=0;i--){
            psumpos[i]=psumpos[i+1];
            if(nums[i]>0){
                psumpos[i]+=nums[i];
            }
        }
        for(int i=1;i<=n+1;i++){
            psumneg[i]=psumneg[i-1];
            if(nums[i]<0){
                psumneg[i]+=-nums[i];
            }
        }
        ll maxi=0;
        for(int i=1;i<=n;i++){
            ll temp=psumpos[0]-psumpos[i];
            temp+=psumneg[n]-psumneg[i-1];
            maxi=max(maxi,temp);
            temp=psumpos[0]-psumpos[i+1];
            temp+=psumneg[n]-psumneg[i];
            maxi=max(maxi,temp);
        }
        cout << maxi << "\n";
    }
}
