#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#define ALL(x) x.begin(),x.end()
#define REV(x) x.rbegin(),x.rend()
using namespace std;
using namespace __gnu_pbds;
typedef long long ll;
typedef tree<int,null_type,less_equal<int>,rb_tree_tag,tree_order_statistics_node_update> intset;
double r,x,y;
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    while(cin >> r >> x >> y){
        double dist=sqrt(x*x+y*y);
        if(dist>=r){
            cout << "miss\n";
            continue;
        }
        double height=sqrt(r*r-x*x-y*y);
        double mini=r*r*asin(height/r)-height*dist;
        cout << fixed << setprecision(6) << r*r*M_PI-mini << ' ' << mini << '\n';
    }
}