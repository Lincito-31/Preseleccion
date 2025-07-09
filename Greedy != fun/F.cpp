#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int n;
ll last,suma,a;
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin >> n;
    while(n--){
        cin >> a;
        suma+=max(last-(a+=suma),0ll);
        last=max(a,last);
    }
    cout << suma;
}