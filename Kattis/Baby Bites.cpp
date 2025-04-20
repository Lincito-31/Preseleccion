#include <bits/stdc++.h>
using namespace std;
int t,n;
string st;
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin >> t;
    for(int i=1;i<=t;i++){
        cin >> st;
        if(st!="mumble"){
            n=stoi(st);
            if(n!=i){
                cout << "something is fishy";
                return 0;
            }
        }
    }
    cout << "makes sense";
}