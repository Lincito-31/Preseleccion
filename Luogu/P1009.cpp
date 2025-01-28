#include <bits/stdc++.h>
#define ALL(x) x.begin(),x.end()
using namespace std;
int n;
vector<string> sum(51);
vector<string> fact(51,"0");
string sumar(string x, string y){
    int tamx=x.size(),tamy=y.size();
    if(tamx>tamy){
        swap(x,y);
        swap(tamx,tamy);
    }
    reverse(ALL(x));
    reverse(ALL(y));
    bool sobra=false;
    string res="";
    for(int i=0;i<tamy;i++){
        if(i>=tamx){
            x.push_back('0');
        }
        int aa=x[i]-48+y[i]-48;
        if(sobra){
            aa++;
            sobra=false;
        }
        if(aa>9){
            sobra=true;
            aa%=10;
        }
        res.push_back(aa+48);
    }
    if(sobra){
        res.push_back('1');
    }
    reverse(ALL(res));
    return res;
}
int main(){
    fact[0]=fact[1]="1";
    string res="0";
    for(int i=2;i<51;i++){
        for(int j=0;j<i;j++){
            fact[i]=sumar(fact[i],fact[i-1]);
        }
    }
    scanf("%d",&n);
    for(int i=1;i<=n;i++){
        res=sumar(res,fact[i]);
    }
    cout << res;
}