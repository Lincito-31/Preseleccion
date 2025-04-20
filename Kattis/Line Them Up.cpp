#include <bits/stdc++.h>
#define ALL(x) x.begin(),x.end()
using namespace std;
typedef long long ll;
int n;
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin >> n;
    vector<string> a(n),b;
    for(int i=0;i<n;i++){
        cin >> a[i];
    }
    b=a;
    sort(ALL(b));
    if(a==b){
        cout << "INCREASING";
    }else{
        reverse(ALL(b));
        if(a==b){
            cout << "DECREASING";
        }else{
            cout << "NEITHER";
        }
    }
}