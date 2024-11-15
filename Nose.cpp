#include <bits/stdc++.h>
using namespace std;
vector<long long> fib(50);
int main(){
    fib[1]=fib[2]=1;
    for(int i=3;i<50;i++){
        fib[i]=fib[i-1]+fib[i-2];
        if(fib[i]>=5e8){
            cout << i;
            break;
        }
    }
}