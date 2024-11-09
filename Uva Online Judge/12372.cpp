#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
string x;
int main(){
    int con=0;
    while(cin >> x){
        con++;
        if(x=="#"){
            break;
        }
        printf("Case %d: ",con);
        if(x=="HELLO"){
            printf("ENGLISH");
        }else if(x=="HOLA"){
            printf("SPANISH");
        }else if(x=="HALLO"){
            printf("GERMAN");
        }else if(x=="BONJOUR"){
            printf("FRENCH");
        }else if(x=="CIAO"){
            printf("ITALIAN");
        }else if(x=="ZDRAVSTVUJTE"){
            printf("RUSSIAN");
        }else{
            printf("UNKNOWN");
        }
        printf("\n");
    }
}