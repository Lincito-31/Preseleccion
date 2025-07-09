#include <bits/stdc++.h>
using namespace std;
string s,t,r;
int main(){
    ifstream in("censor.in");
    ofstream out("censor.out");
    in >> s >> t;
    for(int i=0;i<s.size();i++){
        r.push_back(s[i]);
        while(true){
            string temp="";
            for(int j=r.size()-t.size();j<r.size();j++){
                temp.push_back(r[j]);
            }
            if(temp==t){
                for(int j=0;j<t.size();j++){
                    r.pop_back();
                }
            }else{
                break;
            }
        }
    }
    out << r;
}