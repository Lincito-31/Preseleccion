#include <bits/stdc++.h>
#define ALL(x) x.begin(),x.end()
using namespace std;
typedef long long ll;
int n,a;
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin >> n;
    int arr[n];
    arr[0]=1;
    for(int i=2;i<=n;i++){
        cin >> a;
        arr[a+1]=i;
    }
    for(int i=0;i<n;i++){
        cout << arr[i] << ' ';
    }
}