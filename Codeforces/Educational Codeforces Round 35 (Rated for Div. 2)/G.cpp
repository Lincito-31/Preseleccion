#include <bits/stdc++.h>
using namespace std;
int t,n,q;
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> t;
    while(t--){
        cin >> n;
        vector<int> num(n);
        vector<int> res(n);
        for(int i=0;i<n;i++){
            cin >> num[i];
        }
        cin >> q;
        vector<vector<int>> que(q,vector<int>(4,0));
        for(int i=0;i<q;i++){
            cin >> que[i][0] >> que[i][1] >> que[i][2] >> que[i][3];
        }
        for(int i=n-1;i>=0;i--){
            int iz=que[i][]
        }
    }
}