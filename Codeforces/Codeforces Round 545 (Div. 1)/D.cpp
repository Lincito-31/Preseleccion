#include <bits/stdc++.h>
using namespace std;
int k,cant;
string st;
int move(vector<int> x){
    cout << "next ";
    for(auto u:x){
        cout << u << ' ';
    }
    cout << '\n';
    cout.flush();
    cin >> k;
    for(int i=0;i<k;i++){
        cin >> st;
    }
    return k;
}
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    move({0});
    cant=move({0,1});
    while(cant>2){
        move({0});
        cant=move({0,1});
    }
    while(cant>1){
        cant=move({0,1,2,3,4,5,6,7,8,9});
    }
    cout << "done";
}