#include <bits/stdc++.h>
using namespace std;
typedef long long ll;;
ll t,W,H,w,h,x1,x2,y11,y2;
int main(){
    cin >> t;
    while(t--){
        cin >> W >> H;
        cin >> x1 >> y11 >> x2 >> y2;
        cin >> w >> h;
        ll y=min(max(h-y11,0ll),max(y2-(H-h),0ll));
        ll x=min(max(w-x1,0ll),max(x2-(W-w),0ll));
        if(y2-y11+h<=H && x2-x1+w<=W){
            cout << min(x,y) << '\n';
        }else if(y2-y11+h<=H){
            cout <<  y << '\n';
        }else if(x2-x1+w<=W){
            cout << x << '\n';
        }else{
            cout << -1 << '\n';
        }
    }
}