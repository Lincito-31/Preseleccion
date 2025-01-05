#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int t,n,a;
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);cout.tie(NULL);
    vector<vector<string>> res(100);
    res[3]={"169","196","961"};
    for(int i=5;i<=99;i+=2){
        vector<string> nue=res[i-2];
        for(int j=0;j<i-2;j++){
            nue[j].append("00");
        }
        string f="1",s="9";
        f.append(string((i-3)/2,'0'));
        s.append(string((i-3)/2,'0'));
        f.push_back('6');
        s.push_back('6');
        f.append(string((i-3)/2,'0'));
        s.append(string((i-3)/2,'0'));
        f.push_back('9');
        s.push_back('1');
        nue.push_back(f);
        nue.push_back(s);
        res[i]=nue;
    }
    cin >> t;
    while(t--){
        cin >> n;
        if(n==1){
            cout << "1\n";
        }else{
            for(int i=0;i<n;i++){
                cout << res[n][i] << "\n";
            }
        }
    }
}