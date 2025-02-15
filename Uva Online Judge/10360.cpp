#include <bits/stdc++.h>
using namespace std;
int t,n,d,a,b,c;
int city[1025][1025];
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);cout.tie(nullptr);
    cin >> t;
    while(t--){
        cin >> d >> n;
        for(int i=0;i<1025;i++){
            for(int j=0;j<1025;j++){
                city[i][j]=0;
            }
        }
        int maxi=0,x,y;
        while(n--){
            cin >> a >> b >> c;
            for(int i=max(a-d,0);i<=min(a+d,1024);i++){
                for(int j=max(b-d,0);j<=min(b+d,1024);j++){
                    city[i][j]+=c;
                    if(maxi<city[i][j]){
                        maxi=city[i][j];
                        x=i;
                        y=j;
                    }
                }
            }
        }
        cout << x << ' ' << y << ' ' << maxi << '\n';
    }
}