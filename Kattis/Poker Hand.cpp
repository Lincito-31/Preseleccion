#include <bits/stdc++.h>
#define ALL(x) x.begin(),x.end()
using namespace std;
typedef long long ll;
string c[5];
int maxi,con=1;
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin >> c[0] >> c[1] >> c[2] >> c[3] >> c[4];
    sort(c,c+5);
    for(int i=1;i<5;i++){
        if(c[i][0]==c[i-1][0]){
            con++;
        }else{
            maxi=max(maxi,con);
            con=1;
        }
    }
    cout << max(maxi,con);
}