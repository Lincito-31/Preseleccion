#include <bits/stdc++.h>
using namespace std;
vector<bool> criba(1e8);
int main(){
    criba[0]=criba[1]=true;
    for(int i=4;i<1e8;i+=2){
        criba[i]=true;
    }
}