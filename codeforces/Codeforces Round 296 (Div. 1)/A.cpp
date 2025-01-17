#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int w,h,n,a;
char t;
int main(){
    scanf("%d%d%d",&w,&h,&n);
    multiset<int> W,H;
    multiset<int> mW,mH;
    W.insert(0);
    W.insert(w);
    H.insert(0);
    H.insert(h);
    mW.insert(w);
    mH.insert(h);
    while(n--){
        scanf(" %c%d",&t,&a);
        if(t=='H'){
            auto p=H.lower_bound(a);
            auto pp=p;
            pp--;
            mH.erase(mH.find(*p-*pp));
            mH.insert(a-*pp);
            mH.insert(*p-a);
            H.insert(a);
        }else{
            auto p=W.lower_bound(a);
            auto pp=p;
            pp--;
            mW.erase(mW.find(*p-*pp));
            mW.insert(a-*pp);
            mW.insert(*p-a);
            W.insert(a);
        }
        printf("%lld\n",(ll)(*mW.rbegin())*(ll)(*mH.rbegin()));
    }
}