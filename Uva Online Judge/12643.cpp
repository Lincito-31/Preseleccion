#include <bits/stdc++.h>
using namespace std;
int n,a,b,con;
int main(){
    while(cin >> n >> a >> b){
        a--;b--;
        con=1;
        if(a>b){
            swap(a,b);
        }
        while(!(b%2==1 && b==a+1)){
            con++;
            if(a%2==1){
                a--;
            }
            if(b%2==1){
                b--;
            }
            a/=2;
            b/=2;
        }
        cout << con << '\n';
    }
}