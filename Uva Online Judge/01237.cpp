#include <bits/stdc++.h>
using namespace std;
int t,n,q,a,con;
bool xd;
string names;
pair<string,pair<int,int>> opc[10000];
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin >> t;
    while(t--){
        if(xd){
            cout << '\n';
        }
        xd=true;
        cin >> n;
        for(int i=0;i<n;i++){
            cin >> opc[i].first >> opc[i].second.first >> opc[i].second.second;
        }
        cin >> q;
        while(q--){
            con=0;
            cin >> a;
            for(int i=0;i<n;i++){
                if(opc[i].second.first<=a && a<=opc[i].second.second){
                    con++;
                }
            }
            if(con==1){
                for(int i=0;i<n;i++){
                    if(opc[i].second.first<=a && a<=opc[i].second.second){
                        cout << opc[i].first << '\n';
                    }
                }
            }else{
                cout << "UNDETERMINED" << '\n';
            }
        }
    }
}