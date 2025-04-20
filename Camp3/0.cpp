#include <bits/stdc++.h>
using namespace std;
int q,r;
int main(){
    while(cin >> q >> r){
        if(q<15){
            cout << 0 << "\n";
            continue;
        }
        int a=r-15;
        r-=q;
        int k=a/r;
        while(a/k<r){
            k--;
            if(k<=0){
                break;
            }
        }
        if(k==0){
            //nada
        }else{
            while(r<=a/k){
                k++;
            }
            k--;
        }
        cout << k << "\n";
    }
}
/*
21 24
22 24
23 24
15 24
10 24

3
4
9
1
0
*/