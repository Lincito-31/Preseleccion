#include <bits/stdc++.h>
using namespace std;
int n,alfa[26],counta[26],countb[26];
string a,b;
int main(){
    ifstream in("blocks.in");
    ofstream out("blocks.out");
    in >> n;
    while(n--){
        in >> a >> b;
        for(int i=0;i<26;i++){
            counta[i]=countb[i]=0;
        }
        for(auto u:a){
            counta[u-'a']++;
        }
        for(auto u:b){
            countb[u-'a']++;
        }
        for(int i=0;i<26;i++){
            alfa[i]+=max(counta[i],countb[i]);
        }
    }
    for(int i=0;i<26;i++){
        out << alfa[i] << '\n';
    }
}