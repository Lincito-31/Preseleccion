#include <bits/stdc++.h>
using namespace std;
int t,n;
int arr[1000];
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin >> t;
    while(t--){
        cin >> n;
        for(int i=0;i<n;i++){
            cin >> arr[i];
        }
        for(int i=1;i<n-1;i++){
            if(arr[i-1]<arr[i] && arr[i]<arr[i+1]){
                continue;
            }
            if(arr[i-1]<arr[i+1]){
                cout << i+1 << '\n';
            }else{
                cout << i+2 << '\n';
            }
            break;
        }
    }
}