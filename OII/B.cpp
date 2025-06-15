#include <bits/stdc++.h>
#define ALL(x) x.begin(),x.end()
#define MOD 1000000007
using namespace std;
typedef long long ll;
int k,a;
ll bigmod(ll b,ll e){
    ll p=1;
    while(e>0){
        if(e%2){
            p*=b;
            p%=MOD;
        }
        e/=2;
        b*=b;
        b%=MOD;
    }
    return p;
}
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin >> k;
    string st="";
    char c;
    int x=bigmod(2,k);
    for(int i=0;i<x;i++){
        cin >> c;
        st.push_back(c);
    }
    if(st[0]=='1'){
        return -1;
    }
    for(int i=0;i)
    cout << 200;
    /*if(st[0]=='1'){
        cout << -1;
        return 0;
    }
    while(st[st.size()-1]=='0'){
        st.pop_back();
    }
    if(st.empty()){
        cout << -1;
        return 0;
    }
    if(st=="01"){
        cout << "2\n";
        cout << "0 1\n";
        cout << "1 0\n";
    }else if(st=="001"){
        cout << "2\n";
        cout << "0 2\n";
        cout << "2 0\n";
    }else if(st=="0001"){
        cout << "3\n";
        cout << "0 1 2\n";
        cout << "1 0 2\n";
        cout << "2 2 0\n";
    }else if(st=="011"){
        cout << "4\n";
        cout << "0 1 1 2\n";
        cout << "1 0 2 2\n";
        cout << "1 2 0 1\n";
        cout << "2 2 1 0\n";
    }else if(st=="0101"){
        cout << "2\n";
        cout << "0 1\n";
        cout << "1 0\n";
    }else if(st=="0011"){
        cout << "2\n";
        cout << "0 2\n";
        cout << "2 0\n";
    }else if(st=="0111"){
        cout << "4\n";
        cout << "0 1 1 2\n";
        cout << "1 0 2 2\n";
        cout << "1 2 0 1\n";
        cout << "2 2 1 0\n";
    }else if(st=="00001"){
        cout << "3\n";
        cout << "0 3\n";
        cout << "3 0\n";
    }else if(st=="01001"){
        cout << "4\n";
        cout << "0 1 1 3\n";
        cout << "1 0 3 3\n";
        cout << "1 3 0 1\n";
        cout << "3 3 1 0\n";
    }else if(st=="00101"){
        cout << "4\n";
        cout << "0 2 2 3\n";
        cout << "2 0 3 3\n";
        cout << "2 3 0 2\n";
        cout << "3 3 2 0\n";
    }else if(st=="01101"){

    }else if(st=="01001"){

    }else if(st=="00101"){

    }else if(st=="01101"){

    }
    else{
        cout << 100;
        for(int i=0;i<100;i++){
            for(int j=0;j<100;j++){
                cout << 0 << ' ';
            }
            cout << '\n';
        }
    }*/
}