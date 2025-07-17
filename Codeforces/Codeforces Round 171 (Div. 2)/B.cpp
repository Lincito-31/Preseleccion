#include <bits/stdc++.h>
#define ALL(x) x.begin(),x.end()
using namespace std;
int n,m,suma,maxi;
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin >> n >> m;
    int arr[n];
    for(int i=0;i<n;i++){
        cin >> arr[i];
    }
    int l=0;
    for(int i=0;i<n;i++){
        if(suma+arr[i]<=m){
            suma+=arr[i];
            maxi=max(i-l+1,maxi);
        }else{
            suma-=arr[l];
            i--;
            l++;
        }
    }
    cout << maxi;
}