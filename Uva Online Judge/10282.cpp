#include <bits/stdc++.h>
using namespace std;
string st;
map<string,string> dic;
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);cout.tie(NULL);
    while(getline(cin,st)){
        if(st.empty()){
            break;
        }
        stringstream x(st);
        string y,z;
        x>>y;
        x>>z;
        dic[z]=y;
    }
    while(cin>>st){
        if(dic[st]==""){
            cout << "eh\n";
        }else{
            cout << dic[st] << "\n";
        }
    }
}