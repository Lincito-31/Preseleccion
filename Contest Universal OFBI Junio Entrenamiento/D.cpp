#include <bits/stdc++.h>
#define ALL(x) x.begin(),x.end()
using namespace std;
int n;
bool bb,cc;
string x,a,b,c;
float num1,num2,num3;
map<pair<int,int>,int> mapa;
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin >> n;
    vector<pair<int,int>> nos(n);
    for(int i=0;i<n;i++){
        cc=bb=false;
        a=b=c="";
        cin >> x;
        //cout << x << ' ';
        for(int j=1;j<x.size();j++){
            if(x[j]==')' || x[j]=='/'){
                cc=true;
                continue;
            }
            if(x[j]=='+'){
                bb=true;
                continue;
            }
            if(cc){
                c.push_back(x[j]);
            }else if(bb){
                b.push_back(x[j]);
            }else{
                a.push_back(x[j]);
            }
        }
        //cout << a << ' ' << b << ' ' << c << '\n';
        stringstream help(a);
        help >> num1;
        help=stringstream(b);
        help >> num2;
        help=stringstream(c);
        help >> num3;
        num1*=100;
        num2*=100;
        num3*=100;
        int numer=num1+num2,denom=num3;
        int gcd=__gcd(numer,denom);
        numer/=gcd;
        denom/=gcd;
        nos[i]={numer,denom};
        mapa[{numer,denom}]++;
    }
    for(int i=0;i<n;i++){
        cout << mapa[nos[i]] << ' ';
    }
}