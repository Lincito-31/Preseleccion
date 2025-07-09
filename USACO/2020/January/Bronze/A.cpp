#include <bits/stdc++.h>
using namespace std;
int n,k,tam;
string last,st;
int main(){
    ifstream in("word.in");
    ofstream out("word.out");
    in >> n >> k;
    in >> st;
    last=st;
    tam=st.size();
    while(--n){
        in >> st;
        if(tam+st.size()<=k){
            last+=" "+st;
            tam+=st.size();
        }else{
            out << last << '\n';
            tam=st.size();
            last=st;
        }
    }
    out << last;
}