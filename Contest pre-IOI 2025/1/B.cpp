#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll k;
vector<ll> nums;
vector<ll> temp;
bool xd=false,xd1=false,xd2=false;
void solve(ll cantinow,ll pos){
    if(cantinow==6){
        if(xd1){
            printf("\n");
        }
        xd2=false;
        xd1=true;
        for(ll j=0;j<6;j++){
            if(xd2){
                printf(" ");
            }
            xd2=true;
            printf("%lld",temp[j]);
        }
        return;
    }
    if(pos>=k){
        return;
    }
    temp.push_back(nums[pos]);
    solve(cantinow+1,pos+1);
    temp.pop_back();
    solve(cantinow,pos+1);
}
int main(){
    while(true){
        scanf("%lld",&k);
        if(k==0){
            break;
        }
        if(xd){
            printf("\n\n");
        }
        xd=true;
        xd1=false;
        nums.resize(k);
        for(ll i=0;i<k;i++){
            scanf("%lld",&nums[i]);
        }
        solve(0,0);
    }
    printf("\n");
}