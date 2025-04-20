#include <bits/stdc++.h>
using namespace std;
int n,a,mini=1e9,pos=0;
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin >> n;
    for(int i=0;i<n;i++){
        cin >> a;
        if(a<mini){
            mini=a;
            pos=i;
        }
    }
    cout << pos;
}