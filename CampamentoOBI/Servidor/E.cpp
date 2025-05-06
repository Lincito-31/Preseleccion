#include <bits/stdc++.h>
using namespace std;
int n,a,b;
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    while(cin >> n){
        vector<bool> nose(n-1);
        bool xd=true;
        cin >> a;
        for(int i=1;i<n;i++){
            cin >> b;
            if(abs(a-b)>=n || a==b){
                xd=false;
                continue;
            }
            if(nose[abs(a-b)-1]){
                xd=false;
            }
            nose[abs(a-b)-1]=true;
            a=b;
        }
        if(xd){
            cout << "Jolly\n";
        }else{
            cout << "Not jolly\n";
        }
    }
}