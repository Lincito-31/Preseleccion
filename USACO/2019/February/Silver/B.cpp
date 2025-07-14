#include <bits/stdc++.h>
using namespace std;
int n,k,suma[2010][2010],a,b,c,d,cant;
int main(){
    ifstream fin("paintbarn.in");
    ofstream fout("paintbarn.out");
    fin >> n >> k;
    for(int i=0;i<n;i++){
        fin >> a >> b >> c >> d;
        a++;b++;
        suma[a][b]++;
        suma[a][d+1]--;
        suma[c+1][b]--;
        suma[c+1][d+1]++;
    }
    for(int i=1;i<=1005;i++){
        for(int j=1;j<=1005;j++){
            suma[i][j]+=suma[i-1][j]+suma[i][j-1]-suma[i-1][j-1];
            cant+=(suma[i][j]==k);
        }
    }
    fout << cant;
}