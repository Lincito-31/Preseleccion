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
        vector<int> nums(n),psum(n+2);
        vector<vector<int>> last(n+2,vector<int>(32,1e9));
        for(int i=0;i<n;i++){
            cin >> nums[i];
        }
        nums.push_back(0);
        reverse(ALL(nums));
        nums.push_back(1<<30);
        for(int i=1;i<=n+1;i++){
            psum[i]=psum[i-1]^nums[i];
        }
        for(int i=30;i>=0;i--){
            if(nums[n+1]&(1<<i)){
                last[n+1][i]=n+1;
            }
            last[n+1][i]=min(last[n+1][i],last[n+1][i+1]);
        }
        for(int i=n;i>=0;i--){
            for(int j=30;j>=0;j--){
                last[i][j]=min(last[i+1][j],last[i][j+1]);
                if(nums[i]&(1<<j)){
                    last[i][j]=i;
                }
            }
        }
        while(q--){
            cin >> a;
            int ori=a;
            int iz=1;
            while(true){
                int x=last[iz][31-__builtin_clz(a)];
                int temp=ori^psum[x-1];
                if(temp>=nums[x]){
                    temp^=nums[x];
                    iz=x+1;
                    a=temp;
                }else{
                    iz=x;
                    break;
                }
            }
            cout << iz-1 << ' ';
        }
        cout << '\n';
    }
}
