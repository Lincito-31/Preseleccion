#include <bits/stdc++.h>
#define ALL(x) x.begin(),x.end()
using namespace std;
typedef long long ll;
int arr[3];
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin >> arr[0] >> arr[1] >> arr[2];
    sort(arr,arr+3);
    if(2*arr[1]==arr[0]+arr[2]){
        cout << 2*arr[2]-arr[1];
    }else{
        if(arr[1]-arr[0]<arr[2]-arr[1]){
            cout << 2*arr[1]-arr[0];
        }else{
            cout << arr[0]+arr[2]-arr[1];
        }
    }
}