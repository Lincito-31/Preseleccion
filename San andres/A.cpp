#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef vector<long long> vll;
int n,m,a,b;
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin >> n >> m;
    string x,y;
    vector<pair<int,int>> gra[n+1];
    getline(cin,x);
    for(int i=1;i<=n;i++){
        getline(cin,x);
        stringstream in1(x);
        getline(cin,y);
        stringstream in2(y);
        while(in1 >> a){
            in2 >> b;
            gra[a].push_back({i,b});
        }
    }
    cout << n << " " << m << "\n";
    for(int i=1;i<=n;i++){
        if(gra[i].empty()){
            cout << 0 << "\n";
            continue;
        }
        for(auto u:gra[i]){
            cout << u.first << " ";
        }
        cout << "\n";
        for(auto u:gra[i]){
            cout << u.second << " ";
        }
        cout << "\n";
    }
}