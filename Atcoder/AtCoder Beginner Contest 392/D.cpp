#include <bits/stdc++.h>
using namespace std;

long long N,M;
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);cout.tie(NULL);
    cin >> N;
    vector<vector<long long>> dados(N);
    vector<vector<long long>> contador(N,vector<long long>(1e5+1,0));
    vector<vector<long long>> res(N,vector<long long>(N,0));
    vector<long long> cantidad(N);
    for(long long i=0;i<N;i++){
        cin >> cantidad[i];
        vector<long long> Ahora(cantidad[i]);
        for(long long j=0;j<cantidad[i];j++){
            cin >> Ahora[j];
            contador[i][Ahora[j]]++;
        }
        dados[i]=Ahora;
    }
    double maxi=0;
    for(long long i=0;i<N;i++){
        for(long long j=0;j<i;j++){
            for(long long k=0;k<cantidad[i];k++){
                res[i][j]+=contador[j][dados[i][k]];
            }
            long long numerador=res[i][j];
            long long denominador=cantidad[i]*cantidad[j];
            long long mcd=__gcd(numerador,denominador);
            numerador/=mcd;
            denominador/=mcd;
            maxi=max(maxi,(double)numerador/(double)(denominador));
        }
    }
    cout << fixed << setprecision(15) << maxi;
}