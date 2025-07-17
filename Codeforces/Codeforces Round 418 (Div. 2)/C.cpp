#include <bits/stdc++.h>
#define ALL(x) x.begin(),x.end()
using namespace std;
int n,m,q,cant=1,res;
char c;
string st;
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin >> n;
    cin >> st;
    cin >> q;
    while(q--){
        cin >> cant >> c;
        res=cant;
        int l=0;
        int suma=0,acumu=0;
        for(int i=0;i<n;i++){
            suma++;
            if(st[i]==c){
                acumu++;
                suma--;
            }
            if(cant>=suma){
                res=max(res,acumu+suma);
            }else{
                if(l==i){
                    l=i+1;
                    suma=acumu=0;
                    continue;
                }
                suma-=2;
                if(st[l]==c){
                    acumu--;
                    suma++;
                }
                if(st[i]==c){
                    acumu--;
                    suma++;
                }
                i--;
                l++;
            }
        }
        cout << res << '\n';
    }
}