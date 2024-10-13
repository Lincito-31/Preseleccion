#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#define ALL(x) x.begin(),x.end()
#define REV(x) x.rbegin(),x.rend()
using namespace __gnu_pbds;
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef tree<int,null_type,less<int>,rb_tree_tag,tree_order_statistics_node_update> indexed_set;
typedef pair<int,int> pii;
int t,n,x;
int main(){
    scanf("%d",&t);
    while(t--){
        scanf("%d %d",&n,&x);
        vi nums(n);
        //map<int,int> prueb;
        for(int i=0;i<n;i++){
            scanf("%d",&nums[i]);
            //prueb[nums[i]]++;
        }
        sort(REV(nums));
        ll res=0;
        int acumu=0;
        int con=1;
        int cons=nums[0];
        res+=cons;
        bool xd=false;
        for(int i=0;i<n;i++){
            if(con>x){
                con=1;
                while(acumu<0){
                    if(i==n){
                        xd=true;
                        break;
                    }
                    acumu+=nums[i];
                    i++;
                }
                if(xd){
                    break;
                }
                i--;
                nums[i]=acumu;
                if(i<n-1){
                    cons=max(nums[i],nums[i+1]);
                }else{
                    cons=nums[i];
                }
                res+=cons;
            }
            nums[i]-=cons;
            acumu+=nums[i];
            con++;
        }
        printf("%lld\n",res);
    }
}