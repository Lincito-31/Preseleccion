#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#define MOD 1000000007
#define ALL(x) x.begin(),x.end()
#define REV(x) x.rbegin(),x.rend()
using namespace std;
using namespace __gnu_pbds;
typedef long long ll;
typedef vector<int> vi;
typedef vector<long long> vll;
typedef pair<int,int> pii;
typedef pair<long long,long long> pll;
typedef tree<ll,null_type,less<ll>,rb_tree_tag,tree_order_statistics_node_update> indexed_set;
ll t=1,n,x,y,a;
int main(){
    scanf("%lld",&t);
    while(t--){
        scanf("%lld%lld%lld",&n,&x,&y);
        ll con=0;
        vll nums(n);
        ll sum=0;
        for(int i=0;i<n;i++){
            scanf("%lld",&nums[i]);
            sum+=nums[i];
        }
        sort(ALL(nums));
        for(int i=0;i<n-1;i++){
            ll needy=sum-x-nums[i];
            ll needx=sum-y-nums[i];
            //necesito numeros entre needx y needy;
            int iz=i+1;
            int de=n-1;
            while(iz<de){
                int mid=(iz+de)>>1;
                if(nums[mid]>=needx){
                    de=mid;
                }else{
                    iz=mid+1;
                }
            }
            //cout << needx << " " << needy << endl;
            if(nums[iz]>=needx && nums[iz]<=needy){
                ll limiiz=iz;
                iz=i+1;de=n-1;
                while(iz<de){
                    int mid=(iz+de+1)>>1;
                    if(nums[mid]<=needy){
                        iz=mid;
                    }else{
                        de=mid-1;
                    }
                }
                ll limide=iz;
                con+=limide-limiiz+1;
                //cout << nums[i] << " " << nums[limiiz] << " " << nums[limide] << endl;
            }else{
                continue;
            }
        }
        printf("%lld\n",con);
    }
}