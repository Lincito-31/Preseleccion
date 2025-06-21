#include <bits/stdc++.h>
#define ALL(x) x.begin(),x.end()
using namespace std;
int a,num,now;
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin >> a;
    stack<int> pos;
    for(int i=0;i<32;i++){
        if(a&(1<<i)){
            pos.push(1);
        }else{
            pos.push(0);
        }
    }
    while(pos.top()==0){
        pos.pop();
    }
    while(!pos.empty()){
        num+=pos.top()<<now;
        now++;
        pos.pop();
    }
    cout << num;
}