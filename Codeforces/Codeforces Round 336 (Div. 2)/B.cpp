#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
string s,t;
int psum[200001];
ll sum;
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin >> s >> t;
    for(int i=0;i<t.size();i++){
        psum[i+1]=psum[i];
        psum[i+1]+=t[i]-'0';
    }
    for(int i=0;i<s.size();i++){
        if(s[i]-'0'){
            sum+=t.size()-s.size()+1-(psum[t.size()-s.size()+i+1]-psum[i]);
        }else{
            sum+=psum[t.size()-s.size()+i+1]-psum[i];
        }
    }
    cout << sum;
}