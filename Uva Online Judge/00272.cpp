#include <bits/stdc++.h>
using namespace std;
int con;
string st;
int main(){
    while(getline(cin,st)){
        for(int i=0;i<st.size();i++){
            if(st[i]=='"'){
                if(con){
                    cout << "''";
                }else{
                    cout << "``";
                }
                con=1-con;
            }else{
                cout << st[i];
            }
        }
        cout << "\n";
    }
}