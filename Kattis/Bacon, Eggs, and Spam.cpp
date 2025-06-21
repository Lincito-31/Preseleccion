#include <bits/stdc++.h>
#define ALL(x) x.begin(),x.end()
#define REV(x) x.rbegin(),x.rend()
using namespace std;
typedef long long ll;
int n;
string name,food;
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    while(cin>>n && n){
        cin.ignore();
        map<string,vector<string>> men;
        while(n--){
            getline(cin,name);
            stringstream tot(name);
            tot>>name;
            while(tot>>food){
                men[food].push_back(name);
            }
        }
        for(auto u:men){
            sort(ALL(u.second));
            cout << u.first << ' ';
            for(auto v:u.second){
                cout << v << ' ';
            }
            cout << '\n';
        }
        cout << '\n';
    }
}