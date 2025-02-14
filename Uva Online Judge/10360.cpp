#include <bits/stdc++.h>
using namespace std;
int t,n,d,a,b,c;
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);cout.tie(nullptr);
    cin >> t;
    while(t--){
        int city[1026][1026],psum[1026][1026];
        cin >> d >> n;
        while(n--){
            cin >> a >> b >> c;
            city[a+1][b+1]+=c;
        }
        for(int i=1;i<1026;i++){
            for(int j=1;j<1026;j++){
                psum[i][j]=psum[i][j-1]+city[i][j];
            }
        }
        for(int i=1;i<1026;i++){
            for(int j=1;j<1026;j++){
                psum[i][j]+=psum[i-1][j];
            }
        }
        int x,y,maxi=0;
        for(int i=0;i<1026;i++){
            for(int j=0;j<1026;j++){
                int now=psum[i-d-1][j-d-1]+psum[i+d][j+d]-psum[i+d][j-d-1]-psum[i-d-1][j+d];
            }
        }
    }
}