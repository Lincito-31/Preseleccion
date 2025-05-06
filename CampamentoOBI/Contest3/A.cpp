#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n,x;
int main(){
    cin >> n >> x;
    //if((int)(log10(n)+x)<18){
        /*nu=pow(10,x)-1;
        nu/=9;
        nu*=n;
        //cout << nu << "\n";
        ll suma=0;
        while(nu>0){
            suma+=nu%10;
            nu/=10;
        }
        cout << suma;*/
    //}else{
        ll digi=log10(n)+1;
        vector<int> suma(digi+1),nue(digi);
        ll cop=n;
        int con=0;
        ll sumat=0;
        while(cop>0){
            sumat+=cop%10;
            suma[con++]=sumat;
            nue[con-1]=sumat;
            cop/=10;
        }
        for(int i=digi;i<digi+1;i++){
            suma[i]=suma[i-1];
        }
        int sobra=0,sobraimp;
        for(int i=0;i<digi+1;i++){
            suma[i]+=sobra;
            sobra=suma[i]/10;
            sobraimp=sobra;
            suma[i]%=10;
        }
        int rep=suma[digi];
        //partir de 5
        sumat=0;
        for(int i=0;i<digi+1;i++){
            sumat+=suma[i];
        }
        // tot=x-1;
        ll tot=x-1;
        //empieza del 5 y termina al tot;
        sumat+=(tot-digi)*rep;
        cout << sumat << " ";
        sobra=0;
        while(con>0){
            sumat+=(sobra+nue[--con])%10;
            sobra=(sobra+nue[con])/10;
        }
        sumat+=sobra;
        cout << sumat;
    //}
}
/*
99
 99
  99
   99
109989*/
/*
99 99 891
13 4 16
8 100 800
*/