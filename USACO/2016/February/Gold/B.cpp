#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int n,m;
// empieza en i termina e j con k unlock
int cows[100];
ll dp[100][100][8],resp=1e18;
/*int mitad(int x,int y){
    if(x<y){
        return (x+y)/2;
    }
    y+=n;
    int mid=(x+y)/2;
    return mid%n;
}*/
int main(){
    freopen("cbarn2.in","r",stdin);
    freopen("cbarn2.out","w",stdout);
    cin >> n >> m;
    if(m>=n){
        cout << 0;
        return 0;
    }
    for(int i=0;i<100;i++){
        for(int j=0;j<100;j++){
            for(int k=0;k<8;k++){
                dp[i][j][k]=1e18;
            }
        }
    }
    for(int i=0;i<n;i++){
        cin >> cows[i];
    }
    for(int i=0;i<n;i++){
        int con=1;
        ll suma=0;
        for(int j=(i+1)%n;j!=i;j=(j+1)%n,con++){
            suma+=cows[j]*con;
        }
        dp[i][i][1]=suma;
        //cout << medio << '\n';
        //cout << dp[i][i][1] << '\n';
    }
    for(int k=2;k<=m;k++){
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                // update dp[i][j][k];
                for(int l=i;l<j;l++){
                    ll calc=0;
                    // primero restar del l al i
                    // restar del l al i;
                    int con=1;
                    for(int iii=(l+1)%n;iii!=i;iii=(iii+1)%n,con++){
                        calc-=cows[iii]*con;
                    }
                    // sumar del l al j;
                    con=1;
                    for(int iii=l+1;iii!=j;iii=(iii+1)%n,con++){
                        calc+=cows[iii]*con;
                    }
                    // luego sumar del j al i
                    con=1;
                    for(int iii=j+1;iii!=i;iii=(iii+1)%n,con++){
                        calc+=cows[iii]*con;
                    }
                    dp[i][j][k]=min(dp[i][j][k],dp[i][l][k-1]+calc);
                }
            }
        }
    }
    for(int i=0;i<n;i++){
        for(int j=i;j<n;j++){
            resp=min(resp,dp[i][j][m]);
            //cout << i << ' ' << j << ' ' << dp[i][j][2] << '\n';
        }
    }
    cout << resp;
}