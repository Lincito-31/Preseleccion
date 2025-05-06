#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int n,k,a[100000],can;
ll s;
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin >> n >> k;
    for(int i=0;i<n;i++){
        cin >> a[i];
    }
    sort(a,a+n);
    for(int i=0;i<n;i++){
        a[i]=max(a[i]-i,0);
    }
    sort(a,a+n);
    if(n-k-1>=0){
        can=a[n-k-1];
        s+=(ll)can*k;
        for(int i=0;i<n;i++){
            a[i]=max(a[i]-can,0);
            s+=a[i];
        }
    }else{
        can=0;
        for(int i=0;i<n;i++){
            s+=a[i];
        }
    }
    cout << s;
}