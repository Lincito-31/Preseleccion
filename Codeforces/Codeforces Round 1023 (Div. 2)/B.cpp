#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef vector<long long> vll;
ll t,n,k,sum,maxi,mini,a,con;
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin >> t;
    while(t--){
        sum=maxi=con=0;
        mini=1e9;
        cin >> n >> k;
        while(n--){
            cin >> a;
            sum+=a;
            if(maxi==a){
                con++;
            }else if(maxi<a){
                maxi=a;
                con=1;
            }
            mini=min(mini,a);
        }
        if((con>1 && maxi-mini>k) || ((con==1)&& maxi-1-mini>k) || sum%2==0){
            cout << "Jerry\n";
        }else{
            cout << "Tom\n";
        }
    }
}