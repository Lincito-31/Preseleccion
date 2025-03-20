#include <bits/stdc++.h>
using namespace std;
int a;
bitset<1000001> criba;
vector<int> primes;
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    criba[0]=criba[1]=1;
    for(int i=3;i*i<1000001;i+=2){
        if(!criba[i]){
            for(int j=i*i;j<1000001;j+=i){
                criba[j]=1;
            }
        }
    }
    for(int i=3;i<1000001;i+=2){
        if(!criba[i]){
            primes.push_back(i);
        }
    }
    while(cin >> a){
        if(a==0){
            break;
        }
        if(a%2 || a==2){
            cout << "Goldbach's conjecture is wrong\n";
        }else{
            if(a==4){
                cout << "4 = 2 + 2\n";
            }
            for(auto u:primes){
                if(!criba[a-u]){
                    cout << a << " = " << u << " + " << a-u << "\n";
                    break;
                }
            }
        }
    }
}