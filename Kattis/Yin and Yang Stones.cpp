#include <bits/stdc++.h>
#define ALL(x) x.begin(),x.end()
using namespace std;
typedef long long ll;
string st;
int w;
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin >> st;
    for(int i=0;i<st.size();i++){
        if(st[i]=='W'){
            w++;
        }
    }
    if(2*w==st.size()){
        cout << 1;
    }else{
        cout << 0;
    }
}