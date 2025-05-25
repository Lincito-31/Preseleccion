#include <bits/stdc++.h>
using namespace std;
int t,n,a,b;
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin >> t;
    while(t--){
        bool xd=true;
        cin >> n >> a >> b;
        if(a+b>n || ((a+b)>0 && min(a,b)==0)){
            cout << "NO\n";
            continue;
        }
        vector<int> A(n),B(n);
        vector<bool> used(n);
        for(int i=0;i<n;i++){
            A[i]=i+1;
        }
        for(int i=0;i<n-(a+b);i++){
            B[i]=A[i];
            used[B[i]-1]=true;
        }
        for(int i=n-(a+b);i<n-a;i++){
            B[i]=A[i]+a;
            if(used[B[i]-1]){
                xd=false;
            }
            used[B[i]-1]=true;
        }
        for(int i=n-a;i<n;i++){
            B[i]=A[i]-b;
            if(used[B[i]-1]){
                xd=false;
            }
            used[B[i]-1]=true;
        }
        if(xd){
            cout << "YES\n";
            for(int i=0;i<n;i++){
                cout << A[i] << ' ';
            }
            cout << '\n';
            for(int i=0;i<n;i++){
                cout << B[i] << ' ';
            }
            cout << '\n';
        }else{
            cout << "NO\n";
        }
    }
}