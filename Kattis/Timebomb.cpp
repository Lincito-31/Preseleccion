#include <bits/stdc++.h>
#define ALL(x) x.begin(),x.end()
#define REV(x) x.rbegin(),x.rend()
using namespace std;
typedef long long ll;
typedef long double ld;
string mat[5];
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    for(int i=0;i<5;i++){
        getline(cin,mat[i]);
    }
    int numero=0;
    for(int i=0;i<mat[0].size();i+=3){
        numero*=10;
        if(mat[0][i]==' '){
            numero+=1;
        }else if(mat[1][i]==' '){
            if(mat[2][i]==' '){
                numero+=7;
            }else if(mat[3][i]==' '){
                numero+=3;
            }else{
                numero+=2;
            }
        }else if(mat[0][i+1]==' '){
            numero+=4;
        }else if(mat[3][i]==' '){
            if(mat[1][i+2]==' '){
                numero+=5;
            }else{
                numero+=9;
            }
        }else if(mat[i][i+2]==' '){
            numero+=6;
        }else if(mat[2][i+1]=='*'){
            numero+=8;
        }
    }
    if(numero%6!=0){
        cout << "BOOM!!";
    }else{
        cout << "BEER!!";
    }
}