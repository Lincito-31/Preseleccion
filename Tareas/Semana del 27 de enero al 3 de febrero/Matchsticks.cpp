#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int dp[1000001][2];
int main(){
    // casos bases con numeros de un digito
    dp[0][0]=dp[0][1]=6;
    dp[1][0]=dp[1][1]=2;
    dp[2][0]=dp[2][1]=5;
    dp[3][0]=dp[3][1]=5;
    dp[4][0]=dp[4][1]=4;
    dp[5][0]=dp[5][1]=5;
    dp[6][0]=dp[6][1]=6;
    dp[7][0]=dp[7][1]=3;
    dp[8][0]=dp[8][1]=7;
    dp[9][0]=dp[9][1]=6;
    int limiiz=0,limide=0;
    //Esto es para la mejor forma de usar multiplicacion o simplemente usar los fosoforos para formar la forma del numero
    for(int i=10;i<=1e6;i++){
        int a=i;
        dp[i][0]=dp[i][1]=0;
        while(a>0){
        dp[i][0]+=dp[a%10][0];
        a/=10;
        }
        for(int j=2;j*j<=i;j++){
        if(i%j==0){
            dp[i][0]=min(dp[i][0],dp[j][0]+dp[i/j][0]+2);
        }
        }
        dp[i][1]=dp[i][0];
    }
    //Mejor forma de sacar la suma, como la peor forma es 88888 con 35 fosoforos, entonces hago que i corra solo hasta mitad de 35 para poder mejorar
    for(int i=1;i<1000000;i++){
        if(dp[i][1]>17){
        continue;
        }
        for(int j=1;j<1000000;j++){
        if(i+j>1000000){
            break;
        }
        dp[i+j][1]=min(dp[i+j][1],dp[i][1]+dp[j][1]+2);
        }
    }
    int sum=0;
    for(int i=1;i<=1e6;i++){
        sum+=dp[i][1];
    }
    cout << sum;
    //Después de 26 segundos de correr el programa, me printeo el resultado correcto
    //26688208 accepted
}