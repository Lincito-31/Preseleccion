#include <bits/stdc++.h>
using namespace std;
long long solve(long long x){
    if(x==1){
        return 1;
    }
    if(x%2==0){
        return 2*solve(x/2);
    }
    return solve(x/2)-3*solve((x+1)/2);
}
int main(){
    //Después de unos análisis matematicos concluí que la sumatoria es igual a:
    //4-a_2^11*5^12
    //sabemos que por la primera propiedad:
    //4-a_2^11*5^12=4-2^11*a_5^12
    // entonces usamos recursividad para hallar a_5^12 y ya
    long long res=4-2048*solve(244140625);
    printf("%lld",res);
    // y sale -6999033352333308 AC
}