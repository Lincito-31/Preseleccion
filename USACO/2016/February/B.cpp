#include <bits/stdc++.h>
#define ALL(x) x.begin(),x.end()
using namespace std;
int n,m,now,mini=2e9,timm,canti;
int main(){
    ifstream in("cbarn.in");
    ofstream out("cbarn.out");
    in >> n;
    int cows[n];
    for(int i=0;i<n;i++){
        in >> cows[i];
    }
    for(int i=0;i<n;i++){
        now=(i+1)%n;timm=1;canti=0;
        while(now!=i){
            canti+=cows[now++]*timm++;
            now%=n;
        }
        mini=min(mini,canti);
    }
    out << mini;
}