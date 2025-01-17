#include <bits/stdc++.h>
using namespace std;
string x;
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    vector<string> dic;
    while(cin>>x){
        dic.push_back(x);
    }
    set<string> dif;
    for(int i=0;i<dic.size();i++){
        for(int j=i+1;j<dic.size();j++){
            dif.insert(dic[i]+dic[j]);
            dif.insert(dic[j]+dic[i]);
        }
    }
    for(auto u:dif){
        cout << u << "\n";
    }
}