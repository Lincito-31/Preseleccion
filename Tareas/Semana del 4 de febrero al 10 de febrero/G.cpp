#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int t,n;
map<int,int> posible;
bool solve(int x){
    if(x<0){
        return false;
    }
    if(posible[x]==2){
        return false;
    }else if(posible[x]==1){
        return true;
    }
    int temp=111111111;
    while(temp>=11){
        if(solve(x-temp)){
            return posible[x]=1;
        }
        temp--;
        temp/=10;
    }
    posible[x]=2;
    return false;
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);cout.tie(NULL);
    posible[0]=1;
    cin >> t;
    while(t--){
        cin >> n;
        if(solve(n)){
            cout << "YES\n";
        }else{
            cout << "NO\n";
        }
    }
}