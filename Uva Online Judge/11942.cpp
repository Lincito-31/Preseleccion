#include <bits/stdc++.h>
#define ALL(x) x.begin(),x.end()
#define REV(x) x.rbegin(),x.rend()
using namespace std;
typedef long long ll;
int t,x;
vector<int> a(10),b,c;
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin >> t;
    cout << "Lumberjacks:\n";
    while(t--){
        for(int i=0;i<10;i++){
            cin >> a[i];
        }
        b=c=a;
        sort(ALL(b));
        sort(REV(c));
        if(a==b || a==c){
            cout << "Ordered\n";
        }else{
            cout << "Unordered\n";
        }
    }
}