#include <bits/stdc++.h>
#define ALL(x) x.begin(),x.end()
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef vector<long long> vll;
int n,t,maxi;
bool a,b;
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin >> t;
    while(t--){
        maxi=a=b=0;
        cin >> n;
        vi res(n),nums(n);
        for(int i=0;i<n;i++){
            cin >> nums[i];
            maxi=max(maxi,nums[i]);
        }
        for(int i=0;i<n;i++){
            if(maxi==nums[i]){
                res[i]=2;
                a=true;
            }else{
                res[i]=1;
                b=true;
            }
        }
        if(a&&b){
            cout << "Yes\n";
            for(int i=0;i<n;i++){
                cout << res[i] << ' ';
            }
            cout << '\n';
        }else{
            cout << "No\n";
        }
    }
}