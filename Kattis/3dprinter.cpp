#include <bits/stdc++.h>
#define ALL(x) x.begin(),x.end()
using namespace std;
int a;
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin >> a;
    cout << ceil(log2(a))+1;
}