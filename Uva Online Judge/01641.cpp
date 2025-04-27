#include <bits/stdc++.h>
#define ALL(x) x.begin(),x.end()
#define REV(x) x.rbegin(),x.rend()
using namespace std;
typedef long long ll;
int n,m,area;
bool impar;
char x[100][100];
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    while(cin >> n >> m){
        impar=false;
        area=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                cin >> x[i][j];
                if(x[i][j]=='/' || x[i][j]=='\\'){
                    impar=!impar;
                    area++;
                }else{
                    if(impar){
                        area+=2;
                    }
                }
            }
        }
        cout << area/2 << '\n';
    }
}