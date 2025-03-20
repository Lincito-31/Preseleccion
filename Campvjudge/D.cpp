#include <bits/stdc++.h>
using namespace std;
string S;
int q,a,b,con=0;
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    while(cin >> S){
        cout << "Case " << ++con << ":\n";
        vector<int> ps(S.size()+1);
        for(int i=1;i<=S.size();i++){
            ps[i]=ps[i-1]+S[i-1]-'0';
        }
        cin >> q;
        while(q--){
            cin >> a >> b;
            a++;b++;
            if((abs(a-b)+1)==ps[max(a,b)]-ps[min(a,b)-1] || ps[max(a,b)]-ps[min(a,b)-1]==0){
                cout << "Yes\n";
            }else{
                cout << "No\n";
            }
        }
    }
}