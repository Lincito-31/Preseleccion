#include <bits/stdc++.h>
#define ALL(x) x.begin(),x.end()
using namespace std;
typedef long long ll;
int n,m,con;
double d;
bool xd;
string a,name;
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    while(cin >> n >> m,(n+m)){
        string resname;
        double res=1e9;
        if(xd){
            cout << "\n";
        }
        xd=true;
        int maxi=-1;
        cin.ignore();
        while(n--){
            getline(cin,a);
        }
        while(m--){
            getline(cin,name);
            cin >> d >> n;
            cin.ignore();
            for(int i=0;i<n;i++){
                getline(cin,a);
            }
            if(n>maxi){
                maxi=n;
                resname=name;
                res=d;
            }else if(n==maxi){
                if(d<res){
                    res=d;
                    resname=name;
                }
            }
        }
        cout << "RFP #" << ++con << '\n' << resname << "\n"; 
    }
}