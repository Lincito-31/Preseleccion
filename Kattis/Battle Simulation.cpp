#include <bits/stdc++.h>
#define ALL(x) x.begin(),x.end()
using namespace std;
typedef long long ll;
string st;
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin >> st;
    for(int i=0;i<st.size();i++){
        bool xd=true;
        if(i+2<st.size()){
            string nue="";
            nue.push_back(st[i]);
            nue.push_back(st[i+1]);
            nue.push_back(st[i+2]);
            if(nue=="LRB" || nue=="LBR" || nue=="RLB" || nue=="RBL" || nue=="BLR" || nue=="BRL"){
                cout << 'C';
                xd=false;
                i+=2;
            }
        }
        if(xd){
            if(st[i]=='L'){
                cout << 'H';
            }else if(st[i]=='B'){
                cout << 'K';
            }else{
                cout << 'S';
            }
        }
    }
}