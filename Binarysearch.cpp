#include <bits/stdc++.h>
using namespace std;
int n,q,a;
int main(){
    cin >> n >> q;
    vector<int> x(n);
    for(int i=0;i<n;i++){
        cin >> x[i];
    }
    sort(x.begin(),x.end());
    while(q--){
        cin >> a;
        
        if(binary_search(x.begin(),x.end(),a)){
            cout << "SI" << endl;
        }else{
            cout << "NO" << endl;
        }
    }
}