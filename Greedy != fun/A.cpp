#include <bits/stdc++.h>
using namespace std;
string st;
int last=-1;
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin >> st;
    for(int i=0;i<st.size();i++){
        if((st[i]-'0')%2==0){
            last=i;
            if(st[i]<st.back()){
                swap(st[i],st.back());
                cout << st;
                return 0;
            }
        }
    }
    if(last==-1){
        cout << -1;
    }else{
        swap(st[last],st.back());
        cout << st;
    }
}