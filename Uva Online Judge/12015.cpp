#include <bits/stdc++.h>
#define ALL(x) x.begin(),x.end()
using namespace std;
typedef long long ll;
int t,x;
string T;
vector<string> ranking[100];
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin >> t;
    for(int i=1;i<=t;i++){
        memset(ranking,NULL,sizeof ranking);
        cout << "Case #" << i << ":\n";
        for(int j=0;j<10;j++){
            cin >> T >> x;
            ranking[--x].push_back(T);
        }
        for(int j=99;j>=0;j--){
            if(!ranking[j].empty()){
                for(auto u:ranking[j]){
                    cout << u << '\n';
                }
                break;
            }
        }
    }
}