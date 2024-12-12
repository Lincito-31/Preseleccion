#include <bits/stdc++.h>
using namespace std;
int n,a,b;
string st;
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);cout.tie(NULL);
    cin >> n;
    while(n--){
        a=-1,b=-1;
        cin >> st;
        for(int i=0;i<st.size();i++){
            if(st[i]=='+'){
                a=stoi(st.substr(0,i));
                b=stoi(st.substr(i+1,st.size()-(i+1)));
                break;
            }
        }
        if(a==-1){
            cout << "skipped\n";
        }else{
            a+=b;
            cout << a << "\n";
        }
    }
}