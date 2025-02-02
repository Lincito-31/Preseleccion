#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#define MOD 1000000007
#define ALL(x) x.begin(),x.end()
#define REV(x) x.rbegin(),x.rend()
#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
using namespace __gnu_pbds;
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef vector<long long> vll;
typedef pair<int,int> pii;
typedef pair<long long,long long> pll;
typedef tree<int,null_type,less_equal<int>,rb_tree_tag,tree_order_statistics_node_update> intset;
int t=1,n,k;
int main(){
    FASTIO;
    cin >> t;
    while(t--){
        cin >> n >> k;
        vi nums(n);
        int canti=n-k;
        for(int i=0;i<n;i++){
            cin >> nums[i];
        }
        //nums.push_back(0);
        int now=1,res=-1;
        int tengo=1;
        int i=1;
        while(i<n){
            if(nums[i]!=now){
                if(res!=-1 && res<now){
                    break;
                }
                res=now;
                break;
            }else{
                if(canti>0){
                    if(i+1==n){
                        break;
                    }
                    if(nums[i+1]!=now+1){
                        res=now+1;

                    }
                    i++;
                    canti--;
                }else{
                    i+=2;
                    now++;
                }
            }
        }
        if(res==-1){
            res=now;
        }
        cout << res << "\n";
    }
}
