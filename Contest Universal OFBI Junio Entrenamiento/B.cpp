#include <bits/stdc++.h>
#define ALL(x) x.begin(),x.end()
using namespace std;
int n;
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin >> n;
    vector<int> ar(n);
    for(int i=0;i<n;i++){
        cin >> ar[i];
    }
    sort(ALL(ar));
    for(int i=0;i<n;i++){
        cout << ar[i] << ' ';
    }
}