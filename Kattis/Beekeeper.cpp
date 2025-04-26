#include <bits/stdc++.h>
#define ALL(x) x.begin(),x.end()
using namespace std;
typedef long long ll;
int t,con,maxi;
string x,res;
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    while(cin >> t && t){
        maxi=-1;
        while(t--){
            con=0;
            cin >> x;
            for(int i=1;i<x.size();i++){
                if(x[i]==x[i-1] && (x[i]=='a' || x[i]=='o' || x[i]=='e' || x[i]=='i' || x[i]=='u' || x[i]=='y')){
                    con++;
                }
            }
            if(maxi<con){
                maxi=con;
                res=x;
            }
        }
        cout << res << '\n';
    }
}