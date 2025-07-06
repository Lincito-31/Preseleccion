#include <bits/stdc++.h>
#define ALL(x) x.begin(),x.end()
using namespace std;
int n,t,a,sum,c;
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin >> t;
    while(t--){
        sum=0;
        cin >> n >> c;
        vector<int> con(100);
        while(n--){
            cin >> a;
            con[--a]++;
        }
        for(int i=0;i<100;i++){
            sum+=min(con[i],c);
        }
        cout << sum << '\n';
    }
}