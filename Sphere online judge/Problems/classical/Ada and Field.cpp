#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll w,h,n,a,t,tt;
int main(){
    scanf("%lld",&tt);
    while(tt--){
        scanf("%lld%lld%lld",&w,&h,&n);
        multiset<ll> W,H;
        multiset<ll> mW,mH;
        W.insert(0);
        W.insert(w);
        H.insert(0);
        H.insert(h);
        mW.insert(w);
        mH.insert(h);
        while(n--){
            scanf("%lld%lld",&t,&a);
            if(t==1){
                if(a==0 || a==h){
                    printf("%lld\n",*mW.rbegin()**mH.rbegin());
                    continue;
                }
                auto p=H.lower_bound(a);
                auto pp=p;
                pp--;
                mH.erase(mH.find(*p-*pp));
                mH.insert(a-*pp);
                mH.insert(*p-a);
                H.insert(a);
            }else{
                if(a==0 || a==w){
                    printf("%lld\n",*mW.rbegin()**mH.rbegin());
                    continue;
                }
                auto p=W.lower_bound(a);
                auto pp=p;
                pp--;
                mW.erase(mW.find(*p-*pp));
                mW.insert(a-*pp);
                mW.insert(*p-a);
                W.insert(a);
            }
            printf("%lld\n",*mW.rbegin()**mH.rbegin());
        }
    }
}