#include <bits/stdc++.h>
using namespace std;
string S;
typedef long long ll;
map<int,long double> Gabriel;
map<int,int> res;
vector<ll> fact(10000);
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    Gabriel[1]=0;
    for(int i=2;i<1000000;i++){
        Gabriel[i]=Gabriel[i-1]+(long double)log10(i);
    }
    for(int i=1;i<1000000;i++){
        res[1+(int)Gabriel[i]]=i;
    }
    fact[0]=1;
    /*for(int i=1;fact[i-1]<=1e18;i++){
        fact[i]=fact[i-1]*i;
        if(res[to_string(fact[i]).size()]!=i){
            cout << i << " ";
        }
    }*/
    while(cin >> S){
        if(S=="1"){
            cout << 1;
        }else if(S=="2"){
            cout << 2;
        }else if(S=="6"){
            cout << 3;
        }else if(S=="24"){
            cout << 4;
        }else if(S=="120"){
            cout << 5;
        }else if(S=="720"){
            cout << 6;
        }else{
            cout << res[S.size()];
        }
        cout << "\n";
    }
}