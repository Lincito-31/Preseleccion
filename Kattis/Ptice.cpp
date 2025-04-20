#include <bits/stdc++.h>
#define ALL(x) x.begin(),x.end()
using namespace std;
typedef long long ll;
int n,A,B,G;
string st,Ad="ABC",Br="BABC",Go="CCAABB";
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin >> n >> st;
    for(int i=0;i<n;i++){
        if(st[i]==Ad[i%3]){
            A++;
        }
        if(st[i]==Br[i%4]){
            B++;
        }
        if(st[i]==Go[i%6]){
            G++;
        }
    }
    cout << max({A,B,G}) << "\n";
    if(A==max({A,B,G})){
        cout << "Adrian\n";
    }
    if(B==max({A,B,G})){
        cout << "Bruno\n";
    }
    if(G==max({A,B,G})){
        cout << "Goran\n";
    }
}