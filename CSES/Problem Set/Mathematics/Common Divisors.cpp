#include <bits/stdc++.h>
#define MOD 1000000007
using namespace std;
typedef long long ll;
int n,x,maxi;
int con[1000001];
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin >> n;
    while(n--){
        cin >> x;
        con[x]++;
    }
    for(int i=1000000;i>=0;i--){
        int can=0;
        for(int j=i;j<=1000000;j+=i){
            can+=con[j];
        }
        if(can>1){
            cout << i;
            break;
        }
    }
}