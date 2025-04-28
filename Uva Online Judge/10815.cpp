#include <bits/stdc++.h>
using namespace std;
string st;
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);cout.tie(NULL);
    vector<string> vec;
    while(cin >> st){
        int n=st.size();
        string x="";
        for(int i=0;i<n;i++){
            if((st[i]>=65 && st[i]<=90)||(st[i]>=97 && st[i]<=122)){
                if(st[i]<=90){
                    st[i]+=32;
                }
                x.push_back(st[i]);
            }else{
                vec.push_back(x);
                x="";
            }
        }
        vec.push_back(x); 
    }
    sort(vec.begin(),vec.end());
    string ante="";
    for(auto u:vec){
        if(u==ante){
            continue;
        }
        ante=u;
        cout << u << "\n";
    }
}