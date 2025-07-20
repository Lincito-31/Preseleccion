#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int t,n;
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin >> t;
    while(t--){
        cin >> n;
        vector<map<int,int>> maxi(n);
        int arr[n],res[n];
        for(int i=0;i<n;i++){
            res[i]=0;
            cin >> arr[i];
            maxi[i][arr[i]]=1;
            res[0]=max(res[0],arr[i]);
        }
        for(int i=1;i<n;i++){
            for(auto u:maxi[i-1]){
                int nue=__gcd(u.first,arr[i]);
                maxi[i][nue]=max(maxi[i][nue],u.second+1);
                res[maxi[i][nue]-1]=max(res[maxi[i][nue]-1],nue);
            }
        }
        for(int i=0;i<n;i++){
            cout << res[i] << ' ';
        }
        cout << '\n';
    }
}