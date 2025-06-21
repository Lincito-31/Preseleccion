#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#define ALL(x) x.begin(),x.end()
#define REV(x) x.rbegin(),x.rend()
using namespace std;
using namespace __gnu_pbds;
typedef long long ll;
typedef tree<int,null_type,less_equal<int>,rb_tree_tag,tree_order_statistics_node_update> intset;
int n,m;
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin >> n;
    while(n--){
        double deg=90,x=0,y=0,a,b;
        cin >> m;
        while(m--){
            cin >> a >> b;
            if(a<0){
                a+=360;
            }
            deg+=a;
            if(deg>=360){
                deg-=360;
            }
            y+=b*sin(deg*M_PI/180);
            x+=b*cos(deg*M_PI/180);
        }
        cout << fixed << setprecision(6) << x <<  ' ' << y << '\n';
    }
}