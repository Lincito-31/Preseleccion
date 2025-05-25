#include <bits/stdc++.h>
using namespace std;
int n;
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin >> n;
    vector<vector<bool>> usedr(n,vector<bool>(2*n)),usedc(n,vector<bool>(2*n));
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            for(int k=0;k<2*n;k++){
                if(!(usedr[i][k] || usedc[j][k])){
                    cout << k << ' ';
                    usedr[i][k]=true;
                    usedc[j][k]=true;
                    break;
                }
            }
        }
        cout << '\n';
    }
}