#include <bits/stdc++.h>
#define ALL(x) x.begin(),x.end()
using namespace std;
int n,cows[50001],maxi,mini[50001];
int main(){
    ifstream in("div7.in");
    ofstream out("div7.out");
    in >> n;
    for(int i=1;i<=n;i++){
        in >> cows[i];
        cows[i]+=cows[i-1];
        cows[i]%=7;
        if(mini[cows[i]]==0){
            mini[cows[i]]=i;
        }
    }
    for(int i=1;i<=n;i++){
        maxi=max(maxi,i-mini[cows[i]]);
    }
    out << maxi;
}